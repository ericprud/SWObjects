# make 4s-insert-query
4STORE=../../4store/src/
4s-insert-query.o: 4s-insert-query.c
	cc -std=gnu99 -fno-strict-aliasing -Wall  -g -O0 -I$(4STORE) -DHAVE_LAQRS -DHAVE_RASQAL_WORLD  -DGIT_REV=\"v1.0.0-7-g0bcda14\" `pkg-config --cflags rasqal glib-2.0 libxml-2.0` `pcre-config --cflags`   -c -o 4s-insert-query.o 4s-insert-query.c

4s-insert-query: 4s-insert-query.o
	cc  -rdynamic  `pkg-config --libs rasqal glib-2.0 libxml-2.0 avahi-client avahi-glib` `pcre-config --libs`  4s-insert-query.o $(4STORE)/common/lib4store.a   -o 4s-insert-query

