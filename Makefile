# Copyright 2017 National University of Singapore
#
# See LICENSE for license information.

TARGET=llvmprof-reader

CC=gcc
CFLAGS=-g

all: ${TARGET}

clean:
	rm -f *.o ${TARGET} *~
