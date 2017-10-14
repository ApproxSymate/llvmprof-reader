# llvmprof-reader

Copyright 2017 National University of Singapore

See `LICENSE` for license information.

Contains `llvmprof-reader` which is a reader of llvmprof.out path profile output of LLVM 3.3. Using LLVM 3.3, follow these steps to generate and read path profiling info, assuming the program name is `<program>.c`.
```
clang-3.3 -emit-llvm -O0 -c <program>.c -o <program>.bc
opt-3.3 -insert-path-profiling -path-profile-early-termination -o <program>.pp.bc <program>.bc
llc-3.3 -filetype=obj <program>.pp.bc -o <program>.pp.o
gcc -L<llvm-3.3-library-path> <program>.pp.o -lprofile_rt
LD_LIBRARY_PATH=<llvm-3.3-library-path> ./a.out
llvmprof-reader llvmprof.out
```
Information on the `llvmprof.out` format for path profiling can be found [here](http://llvm.org/pubs/2010-12-Preuss-PathProfiling.pdf).
