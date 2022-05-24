# Linked and Loader

## Linux GOT與PLT

```
gcc -o a.out -g helloworld.c
```

```
objdump -S a.out
```

## GOT與PLT原理簡析

```
gcc -fPIC -shared addvec.c -o libvec.so
```

```
gcc main.c -o main -L./ -lvec
```

```
objdump -ds main > main.dmp
```
