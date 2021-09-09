#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 25

/* An array of 25 unsigned ints stored on the Stack */
static unsigned int results_buffer[NMAX];

void fibonacci()
{
	/* Step 1: Comment out this line of code. You can simply put // in front of it */
	// results_buffer[0] = 1;
	
	/* Step 2: Replace it by setting a "first" unsigned int variable equal to 1 */
	unsigned int first_num = 1;
	
	/* Step 3: Comment out this line of code */
	// results_buffer[1] = 1;
	
	/* Step 4: Replace it by setting a "second" unsigned int variable equal to 1 */
	unsigned int second_num = 1;
	
	long unsigned int iter;
	for (iter = 2; iter < NMAX; iter++) {
		
		/* Step 5: Create a third unsigned int variable equal 
				   equal to the sum of first and second */
		unsigned int third_num = first_num + second_num;
		
		/* Step 6: Comment out this line */
		// results_buffer[ iter ] = results_buffer[ iter-2 ] + results_buffer[ iter - 1 ];
		
		/* Step 7: Set results_buffer[ iter ] to your third unsigned int variable */
		results_buffer[ iter ] = third_num;
		
		/* Step 8: Set your first variable equal to your second variable */
		first_num = second_num;
		
		/* Step 9: Set your second variable equal to your third variable */
		second_num = third_num;

	}
}

int main(void) {
	
	/* Run 10,000,000 tests */
	long int num_tests = 10000000;

	/* clock_t is a type from #include <time.h> */
	/* clock_t is equivalent to a 64-bit signed integer */
	/* We start the profiling */
	clock_t time_start = clock();
	
	long int iter;
	for (iter = 0; iter < num_tests; ++iter)
		fibonacci();

	/* Obtain the end time and complete the time profile */
	clock_t time_end = clock();

	/* compute average execution time */
	clock_t time_run = time_end - time_start;
	long int num_clk_pulses = CLOCKS_PER_SEC*num_tests;
	
	/* To obtain the average in an efficient manner */
	/* Type cast BOTH long ints to a double and then store */
	double final_avg = (double)(time_end) / (double)(num_clk_pulses) ;

	/* print avg execution time in milliseconds */
	fprintf( stdout, "Start time : %ld\n", time_start );
	fprintf( stdout, "Finish time: %ld\n", time_end );
	fprintf( stdout, "Total time: %ld\n", time_run );
	fprintf( stdout, "Number of Clock Pulses: %ld\n", num_clk_pulses );
	fprintf( stdout, "Avg. execution time: %lf msec\n", final_avg*1000);
	
	return 0;
}
