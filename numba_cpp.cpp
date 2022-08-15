/*
 * A program that checks the performance
 * of a single processor core by finding
 * all prime numbers (0-199999 by default),
 * measuring the time needed by the 
 * platform and writing the result to the log
 *
 * Autor: Cixo
 */

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <cstdlib>


/* Defaults options */
#define DEFAULT_BENCHMARK_SIZE 200000
#define DEFAULT_LOG_FILE "numba_cpp.log"


/* Help text for -h option */
#define HELP_TEXT \
	"Hello in NumbaBenchmark!\n"	\
	"This benchmark is used to test a single CPU "	\
	"core by looking for primes in a given range. "	\
	"The program measures how much time is needed "	\
	"to perform the calculations and saves the "	\
	"result to a file.\n Options:\n\t-s : tested "	\
	"interval (default: " << DEFAULT_BENCHMARK_SIZE	\
	<< ")\n\t-f : log file name (default: " 		\
	<< DEFAULT_LOG_FILE << ")\n\t-h : This help "	\
	"note\n"


/*
 * This function checks if the given 
 * number is prime or not prime. If
 * prime then return true, else 
 * return false.
 * 
 * Params: 
 * ++ number (int): Number to check
 *
 * Return:
 * ++ true: Number is prime
 * ++ false: Number is not prime
 */
static bool 
	isPrime (int number)
{
	/* Get absolute of number */
	number = abs (number);
		
	/* Zero and one is not prime */
	if (number == 0 || number == 1)
		return false;
	
	/* Check all dividers */
	for (int test = 2; test < number; test ++)
		if (number % test == 0)
			return false;
			
	return true;
}


/*
 * This function creates a benchmark 
 * summary from elapsed time and 
 * benchmark range size.
 *
 * Params:
 * ++ time (long): Elapsed time in us
 * ++ side (int): Benchmark area size
 *
 * Return:
 * ++ string: Benchmark summary
 */
static std::string 
	createSummary (long time, int size)
{
	std::string summary;
	
	summary += "Benchmark results:\n";
	summary += "\tTime elapsed: " + std::to_string ((double) (time) / 1000000) + "\n";
	summary += "\tBenchmark size: 0 - " + std::to_string (size) + "\n";
	
	return summary;
}


/*
 * This function creates a single
 * number summary to add it to log.
 * 
 * Params:
 * ++ number (int): Number for summary
 *
 * Return:
 * ++ string: Number summary
 */
static std::string
	createNumberSummary (int number)
{
	std::string summary;
	
	summary += std::to_string (number);
	summary += ": ";
	summary += (isPrime (number)) ? "prime" : "not prime";
	summary += "\n";
	
	return summary;
}


int 
	main (int argc, char *argv[])
{
	/* Set default options */
	int benchmark_size = DEFAULT_BENCHMARK_SIZE;
	std::string log_file_name = DEFAULT_LOG_FILE;
	
	/* Parsing command line options */
	for (int count = 0; count < argc; count ++) {
		/* To change range size */
		if ((std::string) (argv[count]) == "-s") { 
			if (count + 1 < argc)
				benchmark_size = std::stoi (argv[++ count]);
		}
		
		/* To change log file */
		if ((std::string) (argv[count]) == "-f") {
			if (count + 1 < argc)
				log_file_name = argv[++ count];
		}
			
		/* To show help note */
		if ((std::string) (argv[count]) == "-h") {
			std::cout << HELP_TEXT;
			
			return 0;
		}
	}

	/* Create variable to save log */
	std::string log;
	
	/* Save start time */
	auto start = std::chrono::steady_clock::now (); 
	
	/* Check all numbers in range */
	for (int count = 0; count < benchmark_size; count ++)
		log += createNumberSummary (count);
	
	/* Save end time */
	auto end = std::chrono::steady_clock::now ();
	
	/* Calculate elapsed time */
	long time_elapsed = (long) 
	(std::chrono::duration_cast <std::chrono::microseconds> (end - start).count ());
	
	/* Create benchmark summary */
	std::string summary = createSummary (time_elapsed, benchmark_size);
	
	/* Display benchmark summary */
	std::cout << summary;
	
	/* Save benchmark summary to log */
	log += "\n\n";
	log += summary;
	 
	/* Variable to open log file */
	std::fstream log_file;
	
	/* Open log file */
	log_file.open (log_file_name, std::ios::out | std::ios::trunc);
	
	/* If file is not open propertly */
	if (!log_file.good ()){
		
		/* Display log on screen */
		std::cout << "\n\n";
		std::cout << "Save to log error!\n";
		std::cout << "Log:\n" << log;
		
		return 1;
	}
	
	/* Saving log file */
	log_file << log;
	log_file.close ();
	
	return 0;
}