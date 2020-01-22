gcc -c -o staticlib.o staticlib.c
ar rcs libstaticlib.a staticlib.o
gcc -o app app.c libstaticlib.a -ldl
gcc -shared -o libdynlib.so dynlib.c

# https://stackoverflow.com/questions/17862272/dlopen-a-dynamic-library-from-a-static-library-linux-c
