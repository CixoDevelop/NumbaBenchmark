# Python Numba benchmark
A simple benchmark that checks the performance difference after JIT is applied to Python by numba. The benchmark looks for primes in the range 0-199999 and writes the result to a file. The benchmark result is the amount of time it takes to perform the calculations, it is printed on the screen. Work on single core only!

### python3 jit.py (With Numba JIT)
* Time elapsed: 6.884712938

### python3 metal.py (Without Numba JIT)
 * Time elapsed: 182.266834501