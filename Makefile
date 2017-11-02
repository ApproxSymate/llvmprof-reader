# Copyright 2017 National University of Singapore
#
# See LICENSE for license information.

LLVM_3_3_DIR=${HOME}/software/llvm-3.3

TARGET=llvmprof-reader
EXAMPLE=example
LLVMPROF=${EXAMPLE}.llvmprof.out

CC=gcc
CFLAGS=-g

all: ${TARGET}

test: all ${LLVMPROF}
	./${TARGET} ${LLVMPROF}

${LLVMPROF}:
	${LLVM_3_3_DIR}/bin/clang -emit-llvm -O0 -c example.c -o example.bc
	${LLVM_3_3_DIR}/bin/opt -insert-path-profiling -path-profile-early-termination -o example.pp.bc example.bc
	${LLVM_3_3_DIR}/bin/llc -filetype=obj example.pp.bc -o example.pp.o
	${CC} -L${LLVM_3_3_DIR}/lib example.pp.o -lprofile_rt -o example
	LD_LIBRARY_PATH=${LLVM_3_3_DIR}/lib ./example -llvmprof-output $@

clean:
	rm -f *.o ${TARGET} example *~ *.bc *.out *.ll
