all: swobjects.so
clean:
	rm -f *.o *.so swobjects_wrap.c

swobjects_wrap.c:
	swig -lua -module swobjects -I../../ -I../../lib/ -I../../interface/ -o swobjects_wrap.c ../SWObjects.i

swobjects_wrap.o: swobjects_wrap.c
	gcc -fPIC -c swobjects_wrap.c -o swobjects_wrap.o

swobjects.so: swobjects_wrap.o
	gcc -fPIC -shared -I/usr/include/lua -L/usr/lib/lua swobjects_wrap.o -o swobjects.so
