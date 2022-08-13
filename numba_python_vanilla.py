# A program that checks the performance
# of a single processor core by finding
# all prime numbers (0-199999 by default),
# measuring the time needed by the 
# platform and writing the result to the log
#
# Autor: Cixo


from time import process_time
from os.path import isfile
from argparse import ArgumentParser


# Function for cals is number prime
# Return true if prime or false if 
# not prime. Number is number for
# test.

def isPrime (number):
	if number < 0:
		number = -number

	if number == 0 or number == 1:
		return False

	for test in range (2, number):
		if number % test == 0:
			return False
			
	return True


# Function that creates a benchmark
# summary based on the time the 
# benchmark lasted and the range of
# tested numbers.

def createSummary (time, size):
	summary = "Benchmark results:\n"
	summary += "\tTime elapsed: " + str (time) + "\n"
	summary += "\tBenchmark size: 0 - " + str (size) + "\n"
	
	return summary


# Function that summarizes a number,
# returning a string that can be 
# added to log.

def createNumberSummary (number):
	summary = str (number)
	summary += ": "
	summary += "prime" if isPrime (number) else "not prime"
	summary += "\n"
	
	return summary

# Default parameters
benchmark_size = 200000
log_file_name = "numba_python_vanilla.log"

# Argument parser
parser = ArgumentParser (
	description = 
		"Hello in NumbaBenchmark!\nThis benchmark is" + 
		"used to test a single CPU core by looking for" + 
		"primes in a given range. The program measures" + 
		"how much time is needed to perform the " + 
		"calculations and saves the result to a file."
)

# For change benchmark range
parser.add_argument (
	"-s", "--size", 
	help = "tested interval (default: " + str (benchmark_size) +")"
)

# For change log file name
parser.add_argument (
	"-f", "--file", 
	help = "log file name (default: " + log_file_name + ")"
)

# Parse arguments
arguments = parser.parse_args ()

# Process size argument
if arguments.size is not None:
	benchmark_size = int (arguments.size)
	
# Process log file argument
if arguments.file is not None:
	log_file_name = arguments.file

# Log string
log = ""

# Start time
start = process_time ()

# Benchmark on all numbers
for number in range (0, benchmark_size):
	
	# Test all numbers
	log += createNumberSummary (number)
	
# Calculate elapsed time
elapsed_time = process_time () - start

# Create benchmark summary
benchmark_summary = createSummary (elapsed_time, benchmark_size)

# And print it on screen
print (benchmark_summary, end = "")

# And add it to log
log += "\n\n"
log += benchmark_summary
	
# On end, save log to file
with open (log_file_name, "w" if isfile (log_file_name) else "x") as file:
	file.write (log)
