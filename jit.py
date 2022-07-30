# A simple benchmark that checks the performance
# difference after JIT is applied to Python by 
# numba. The benchmark looks for primes in the 
# range 0-199999 and writes the result to a file.
# The benchmark result is the amount of time it 
# takes to perform the calculations, it is printed
# on the screen.


from numba import njit
from time import process_time
from os.path import isfile



# Function for cals is number prime
# Return true if prime or false if 
# not prime. Number is number for
# test.

@njit
def isPrime (number):
	if number < 0:
		number = -number

	if number == 0 or number == 1:
		return False

	for test in range (2, number):
		if number % test == 0:
			return False
			
	return True


# Numbers for benchmark
bench = [x for x in range (0, 200000)]

# String for log
string = ""

# Get time for benchmark
start = process_time ()

# Try all numbers
for number in bench:
	string += str (number)
	string += ": "
	string += ("prime" if isPrime (number) else "not prime")
	string += "\n"
	
# Print benchmark time
print ("Time elapsed: " + str (process_time () - start))		
	
# Same log to file	
with open ("log.jit", "w" if isfile ("log.jit") else "x") as file:
	file.write(string)
	
