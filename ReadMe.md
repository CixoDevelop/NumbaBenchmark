# Numba benchmark
This repository contains programs that test the performance of a single processor core by finding prime numbers in a given range (0-199999 by default). In addition to comparing the performance of different processors, it was also written to compare the performance of vanilla python with performance using the just-in-time compiler Numba (hence the name) and the C++ compiler's.

## Running

### Python3 (With Numba JIT)
 * You must have Numba installed (learn more at http://numba.pydata.org/)
 * python3 numba_python_jit.py

### python3 (Without Numba JIT)
 * You don't need a Numba package
 * python3 numba_python_vanilla.py
 
### C++ 
 * You can compile the project using your favorite compiler, preferably with the highest optimization possible
 * For example, linux and GCC: g++ numba_cpp.cpp -O3 -o numba_cpp.run
 * Or you can use precompiled binaries (for linux x86, linux ARM, windows x86) all compiled natively, no cross compilation, in the bin directory
 * Then run it, for example linux: ./numba_cpp.run
 
## Sample results

### Intel i7-3740QM (Arch Linux x86_64, Turbo Boost off)
 * 5.748610 - C++
 * 10.660679271 - Python JIT
 * 131.175513498 - Python vanilla
 
### Intel i7-3740QM (Arch Linux x86_64, Turbo Boost on)
 * 4.224961 - C++
 * 7.818004449000001 - Python JIT
 * 95.616951256 - Python vanilla
 
### MediaTek mt8173 (Chrome OS, Linux container)
 * 5.840652 - C++
 * 6.885304478 - Python JIT
 * 181.290418972 - Python vanilla
 
