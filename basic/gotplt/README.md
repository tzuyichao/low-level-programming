
gcc -fPIC -shared addvec.c -o libvec.so

gcc main.c -o main -L./ -lvec

objdump -ds main > main.dmp