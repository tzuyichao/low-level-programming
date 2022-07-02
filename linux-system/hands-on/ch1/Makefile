ALL := hello hello_dbg

CC=gcc
CFLAGS_DBG=-g -ggdb -gdwarf-4 -O0 -Wall -Wextra
CFLAGS=-Wall -Wextra

all: ${ALL}
CB_FILES := *.[ch]

hello: hello.c
	$(CC) $(CFLAGS) hello.c -o hello
hello_dbg: hello.c
	$(CC) $(CFLAGS_DBG) hello.c -o hello_dbg
	objdump --source ./hello_dbg > hello_dbg_objdump.txt
cb: ${CB_FILES}
	mkdir bkp 2> /dev/null; cp -f ${CB_FILES} bkp/
	indent -linux ${CB_FILES}
clean:
	rm -vf ${ALL} core* *.o *~
