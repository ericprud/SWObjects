/* SWCrypto.hpp - self-contained message digests for the SPARQL hash builtins
 * (MD5 per RFC 1321; SHA-1/SHA-256/SHA-384/SHA-512 per FIPS 180-4).
 * Digests are computed over the UTF-8 bytes of the input and rendered as
 * lower-case hex, as SPARQL 1.1 sec. 17.4.4 requires.
 */
#ifndef SWCRYPTO_HPP
#define SWCRYPTO_HPP

#include <cmath>
#include <cstdint>
#include <cstring>
#include <string>

namespace w3c_sw {
namespace crypto {

    inline std::string toHex (const uint8_t* digest, size_t len) {
	static const char hex[] = "0123456789abcdef";
	std::string ret(len * 2, '0');
	for (size_t i = 0; i < len; ++i) {
	    ret[i * 2]     = hex[digest[i] >> 4];
	    ret[i * 2 + 1] = hex[digest[i] & 0xf];
	}
	return ret;
    }

    /* ------------------------------------------------------------------ MD5 */

    inline std::string md5Hex (const std::string& input) {
	// T[i] = floor(|sin(i+1)| * 2^32), computed once to avoid a
	// transcribed table.
	static uint32_t T[64];
	static bool init = false;
	if (!init) {
	    for (int i = 0; i < 64; ++i)
		T[i] = (uint32_t)(std::floor(std::fabs(std::sin((double)(i + 1))) * 4294967296.0));
	    init = true;
	}
	static const int R[64] = {
	    7,12,17,22, 7,12,17,22, 7,12,17,22, 7,12,17,22,
	    5, 9,14,20, 5, 9,14,20, 5, 9,14,20, 5, 9,14,20,
	    4,11,16,23, 4,11,16,23, 4,11,16,23, 4,11,16,23,
	    6,10,15,21, 6,10,15,21, 6,10,15,21, 6,10,15,21 };

	uint32_t h[4] = { 0x67452301u, 0xefcdab89u, 0x98badcfeu, 0x10325476u };

	// pad: 0x80, zeros, 64-bit little-endian bit count
	std::string msg = input;
	uint64_t bitLen = (uint64_t)msg.size() * 8;
	msg += (char)0x80;
	while (msg.size() % 64 != 56)
	    msg += (char)0;
	for (int i = 0; i < 8; ++i)
	    msg += (char)((bitLen >> (8 * i)) & 0xff);

	for (size_t off = 0; off < msg.size(); off += 64) {
	    uint32_t M[16];
	    for (int i = 0; i < 16; ++i)
		M[i] = (uint32_t)(uint8_t)msg[off + 4*i]
		    | ((uint32_t)(uint8_t)msg[off + 4*i + 1] << 8)
		    | ((uint32_t)(uint8_t)msg[off + 4*i + 2] << 16)
		    | ((uint32_t)(uint8_t)msg[off + 4*i + 3] << 24);
	    uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
	    for (int i = 0; i < 64; ++i) {
		uint32_t f; int g;
		if (i < 16)      { f = (b & c) | (~b & d);   g = i; }
		else if (i < 32) { f = (d & b) | (~d & c);   g = (5*i + 1) % 16; }
		else if (i < 48) { f = b ^ c ^ d;            g = (3*i + 5) % 16; }
		else             { f = c ^ (b | ~d);         g = (7*i) % 16; }
		uint32_t x = a + f + T[i] + M[g];
		uint32_t rot = (x << R[i]) | (x >> (32 - R[i]));
		a = d; d = c; c = b; b = b + rot;
	    }
	    h[0] += a; h[1] += b; h[2] += c; h[3] += d;
	}

	uint8_t digest[16];
	for (int i = 0; i < 4; ++i)
	    for (int j = 0; j < 4; ++j)
		digest[4*i + j] = (uint8_t)(h[i] >> (8 * j)); // little-endian
	return toHex(digest, 16);
    }

    /* ---------------------------------------------------------------- SHA-1 */

    inline std::string sha1Hex (const std::string& input) {
	uint32_t h[5] = { 0x67452301u, 0xefcdab89u, 0x98badcfeu, 0x10325476u, 0xc3d2e1f0u };

	std::string msg = input;
	uint64_t bitLen = (uint64_t)msg.size() * 8;
	msg += (char)0x80;
	while (msg.size() % 64 != 56)
	    msg += (char)0;
	for (int i = 7; i >= 0; --i)
	    msg += (char)((bitLen >> (8 * i)) & 0xff); // big-endian

	for (size_t off = 0; off < msg.size(); off += 64) {
	    uint32_t w[80];
	    for (int i = 0; i < 16; ++i)
		w[i] = ((uint32_t)(uint8_t)msg[off + 4*i] << 24)
		    | ((uint32_t)(uint8_t)msg[off + 4*i + 1] << 16)
		    | ((uint32_t)(uint8_t)msg[off + 4*i + 2] << 8)
		    |  (uint32_t)(uint8_t)msg[off + 4*i + 3];
	    for (int i = 16; i < 80; ++i) {
		uint32_t x = w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16];
		w[i] = (x << 1) | (x >> 31);
	    }
	    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];
	    for (int i = 0; i < 80; ++i) {
		uint32_t f, k;
		if (i < 20)      { f = (b & c) | (~b & d);           k = 0x5a827999u; }
		else if (i < 40) { f = b ^ c ^ d;                    k = 0x6ed9eba1u; }
		else if (i < 60) { f = (b & c) | (b & d) | (c & d);  k = 0x8f1bbcdcu; }
		else             { f = b ^ c ^ d;                    k = 0xca62c1d6u; }
		uint32_t tmp = ((a << 5) | (a >> 27)) + f + e + k + w[i];
		e = d; d = c; c = (b << 30) | (b >> 2); b = a; a = tmp;
	    }
	    h[0] += a; h[1] += b; h[2] += c; h[3] += d; h[4] += e;
	}

	uint8_t digest[20];
	for (int i = 0; i < 5; ++i)
	    for (int j = 0; j < 4; ++j)
		digest[4*i + j] = (uint8_t)(h[i] >> (24 - 8 * j)); // big-endian
	return toHex(digest, 20);
    }

    /* -------------------------------------------------------------- SHA-256 */

    namespace detail {
	// fractional parts of the cube roots of the first 64 primes
	static const uint32_t sha256K[64] = {
	    0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
	    0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
	    0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
	    0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
	    0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
	    0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
	    0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
	    0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u };

	inline uint32_t rotr32 (uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }
	inline uint64_t rotr64 (uint64_t x, int n) { return (x >> n) | (x << (64 - n)); }

	// fractional parts of the cube roots of the first 80 primes; the high
	// 32 bits of the first 64 are sha256K
	static const uint64_t sha512K[80] = {
	    0x428a2f98d728ae22ull,0x7137449123ef65cdull,0xb5c0fbcfec4d3b2full,0xe9b5dba58189dbbcull,
	    0x3956c25bf348b538ull,0x59f111f1b605d019ull,0x923f82a4af194f9bull,0xab1c5ed5da6d8118ull,
	    0xd807aa98a3030242ull,0x12835b0145706fbeull,0x243185be4ee4b28cull,0x550c7dc3d5ffb4e2ull,
	    0x72be5d74f27b896full,0x80deb1fe3b1696b1ull,0x9bdc06a725c71235ull,0xc19bf174cf692694ull,
	    0xe49b69c19ef14ad2ull,0xefbe4786384f25e3ull,0x0fc19dc68b8cd5b5ull,0x240ca1cc77ac9c65ull,
	    0x2de92c6f592b0275ull,0x4a7484aa6ea6e483ull,0x5cb0a9dcbd41fbd4ull,0x76f988da831153b5ull,
	    0x983e5152ee66dfabull,0xa831c66d2db43210ull,0xb00327c898fb213full,0xbf597fc7beef0ee4ull,
	    0xc6e00bf33da88fc2ull,0xd5a79147930aa725ull,0x06ca6351e003826full,0x142929670a0e6e70ull,
	    0x27b70a8546d22ffcull,0x2e1b21385c26c926ull,0x4d2c6dfc5ac42aedull,0x53380d139d95b3dfull,
	    0x650a73548baf63deull,0x766a0abb3c77b2a8ull,0x81c2c92e47edaee6ull,0x92722c851482353bull,
	    0xa2bfe8a14cf10364ull,0xa81a664bbc423001ull,0xc24b8b70d0f89791ull,0xc76c51a30654be30ull,
	    0xd192e819d6ef5218ull,0xd69906245565a910ull,0xf40e35855771202aull,0x106aa07032bbd1b8ull,
	    0x19a4c116b8d2d0c8ull,0x1e376c085141ab53ull,0x2748774cdf8eeb99ull,0x34b0bcb5e19b48a8ull,
	    0x391c0cb3c5c95a63ull,0x4ed8aa4ae3418acbull,0x5b9cca4f7763e373ull,0x682e6ff3d6b2b8a3ull,
	    0x748f82ee5defb2fcull,0x78a5636f43172f60ull,0x84c87814a1f0ab72ull,0x8cc702081a6439ecull,
	    0x90befffa23631e28ull,0xa4506cebde82bde9ull,0xbef9a3f7b2c67915ull,0xc67178f2e372532bull,
	    0xca273eceea26619cull,0xd186b8c721c0c207ull,0xeada7dd6cde0eb1eull,0xf57d4f7fee6ed178ull,
	    0x06f067aa72176fbaull,0x0a637dc5a2c898a6ull,0x113f9804bef90daeull,0x1b710b35131c471bull,
	    0x28db77f523047d84ull,0x32caab7b40c72493ull,0x3c9ebe0a15c9bebcull,0x431d67c49c100d4cull,
	    0x4cc5d4becb3e42b6ull,0x597f299cfc657e2aull,0x5fcb6fab3ad6faecull,0x6c44198c4a475817ull };

	inline std::string sha512Family (const std::string& input,
					 const uint64_t iv[8], size_t digestBytes) {
	    uint64_t h[8];
	    std::memcpy(h, iv, sizeof(uint64_t) * 8);

	    std::string msg = input;
	    uint64_t bitLen = (uint64_t)msg.size() * 8;
	    msg += (char)0x80;
	    while (msg.size() % 128 != 112)
		msg += (char)0;
	    for (int i = 0; i < 8; ++i)
		msg += (char)0; // high 64 bits of the 128-bit length
	    for (int i = 7; i >= 0; --i)
		msg += (char)((bitLen >> (8 * i)) & 0xff);

	    for (size_t off = 0; off < msg.size(); off += 128) {
		uint64_t w[80];
		for (int i = 0; i < 16; ++i) {
		    w[i] = 0;
		    for (int j = 0; j < 8; ++j)
			w[i] = (w[i] << 8) | (uint8_t)msg[off + 8*i + j];
		}
		for (int i = 16; i < 80; ++i) {
		    uint64_t s0 = rotr64(w[i-15], 1) ^ rotr64(w[i-15], 8) ^ (w[i-15] >> 7);
		    uint64_t s1 = rotr64(w[i-2], 19) ^ rotr64(w[i-2], 61) ^ (w[i-2] >> 6);
		    w[i] = w[i-16] + s0 + w[i-7] + s1;
		}
		uint64_t a = h[0], b = h[1], c = h[2], d = h[3],
		    e = h[4], f = h[5], g = h[6], hh = h[7];
		for (int i = 0; i < 80; ++i) {
		    uint64_t S1 = rotr64(e, 14) ^ rotr64(e, 18) ^ rotr64(e, 41);
		    uint64_t ch = (e & f) ^ (~e & g);
		    uint64_t t1 = hh + S1 + ch + sha512K[i] + w[i];
		    uint64_t S0 = rotr64(a, 28) ^ rotr64(a, 34) ^ rotr64(a, 39);
		    uint64_t maj = (a & b) ^ (a & c) ^ (b & c);
		    uint64_t t2 = S0 + maj;
		    hh = g; g = f; f = e; e = d + t1;
		    d = c; c = b; b = a; a = t1 + t2;
		}
		h[0] += a; h[1] += b; h[2] += c; h[3] += d;
		h[4] += e; h[5] += f; h[6] += g; h[7] += hh;
	    }

	    uint8_t digest[64];
	    for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
		    digest[8*i + j] = (uint8_t)(h[i] >> (56 - 8 * j));
	    return toHex(digest, digestBytes);
	}
    } // namespace detail

    inline std::string sha256Hex (const std::string& input) {
	using namespace detail;
	uint32_t h[8] = { 0x6a09e667u, 0xbb67ae85u, 0x3c6ef372u, 0xa54ff53au,
			  0x510e527fu, 0x9b05688cu, 0x1f83d9abu, 0x5be0cd19u };

	std::string msg = input;
	uint64_t bitLen = (uint64_t)msg.size() * 8;
	msg += (char)0x80;
	while (msg.size() % 64 != 56)
	    msg += (char)0;
	for (int i = 7; i >= 0; --i)
	    msg += (char)((bitLen >> (8 * i)) & 0xff);

	for (size_t off = 0; off < msg.size(); off += 64) {
	    uint32_t w[64];
	    for (int i = 0; i < 16; ++i)
		w[i] = ((uint32_t)(uint8_t)msg[off + 4*i] << 24)
		    | ((uint32_t)(uint8_t)msg[off + 4*i + 1] << 16)
		    | ((uint32_t)(uint8_t)msg[off + 4*i + 2] << 8)
		    |  (uint32_t)(uint8_t)msg[off + 4*i + 3];
	    for (int i = 16; i < 64; ++i) {
		uint32_t s0 = rotr32(w[i-15], 7) ^ rotr32(w[i-15], 18) ^ (w[i-15] >> 3);
		uint32_t s1 = rotr32(w[i-2], 17) ^ rotr32(w[i-2], 19) ^ (w[i-2] >> 10);
		w[i] = w[i-16] + s0 + w[i-7] + s1;
	    }
	    uint32_t a = h[0], b = h[1], c = h[2], d = h[3],
		e = h[4], f = h[5], g = h[6], hh = h[7];
	    for (int i = 0; i < 64; ++i) {
		uint32_t S1 = rotr32(e, 6) ^ rotr32(e, 11) ^ rotr32(e, 25);
		uint32_t ch = (e & f) ^ (~e & g);
		uint32_t t1 = hh + S1 + ch + sha256K[i] + w[i];
		uint32_t S0 = rotr32(a, 2) ^ rotr32(a, 13) ^ rotr32(a, 22);
		uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
		uint32_t t2 = S0 + maj;
		hh = g; g = f; f = e; e = d + t1;
		d = c; c = b; b = a; a = t1 + t2;
	    }
	    h[0] += a; h[1] += b; h[2] += c; h[3] += d;
	    h[4] += e; h[5] += f; h[6] += g; h[7] += hh;
	}

	uint8_t digest[32];
	for (int i = 0; i < 8; ++i)
	    for (int j = 0; j < 4; ++j)
		digest[4*i + j] = (uint8_t)(h[i] >> (24 - 8 * j));
	return toHex(digest, 32);
    }

    inline std::string sha384Hex (const std::string& input) {
	static const uint64_t iv[8] = {
	    0xcbbb9d5dc1059ed8ull, 0x629a292a367cd507ull, 0x9159015a3070dd17ull, 0x152fecd8f70e5939ull,
	    0x67332667ffc00b31ull, 0x8eb44a8768581511ull, 0xdb0c2e0d64f98fa7ull, 0x47b5481dbefa4fa4ull };
	return detail::sha512Family(input, iv, 48);
    }

    inline std::string sha512Hex (const std::string& input) {
	static const uint64_t iv[8] = {
	    0x6a09e667f3bcc908ull, 0xbb67ae8584caa73bull, 0x3c6ef372fe94f82bull, 0xa54ff53a5f1d36f1ull,
	    0x510e527fade682d1ull, 0x9b05688c2b3e6c1full, 0x1f83d9abfb41bd6bull, 0x5be0cd19137e2179ull };
	return detail::sha512Family(input, iv, 64);
    }

} // namespace crypto
} // namespace w3c_sw

#endif /* SWCRYPTO_HPP */
