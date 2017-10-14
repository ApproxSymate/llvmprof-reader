
TARGET=llvmprof-reader

CC=gcc
CFLAGS=-g

all: ${TARGET}

clean:
	rm -f *.o ${TARGET} *~
