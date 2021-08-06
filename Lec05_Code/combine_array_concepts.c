#include <stdio.h>
#include <stdlib.h>

int print_arrays( int array_1[], long unsigned int array_1_len, 
		int* array_2, long unsigned int array_2_len ){
			
	/* These loops perform identical tasks at different levels of abstraction */
		    
    	fprintf( stdout, "%p %p %p %p\n", &array_1, array_1, &array_2, array_2 );

	long unsigned int iter_1;
	int sum_1 = 0;
	for( iter_1 = 0; iter_1 < array_1_len; ++iter_1 ){

		/* Prints data and structure using abstracted array notation */
		/* static_array is static, so the information is in local registers */
		/* The addresses will appear longer than dynamic arrays */
		fprintf( stdout, "%d %p\n", array_1[ iter_1 ], &array_1[iter_1]);
		
		sum_1 += array_1[ iter_1 ];
	}

	long unsigned int iter_2;
	int sum_2 = 0;
	for( iter_2 = 0; iter_2 < array_2_len; ++iter_2 ){

		/* Prints data and structure using pointer casting and arithmetic */
		/* dynamic_array is dynamic, so the information is on the Data Heap */
		fprintf( stdout, "%d %p\n", 
			*( (int *)( (void *)array_2 + iter_2*sizeof(int) )), 
	    		(void *)array_2 + iter_2*sizeof(int) );
				
		sum_2 += *( (int *)( (void *)array_2 + iter_2*sizeof(int) ) ) ;
	}

	return sum_1 + sum_2;

}

int main( void ){

	/* Abstracted Static Array Allocation on the Stack */
	/* Use {} allocation to show simple, high-level allocation */
	int array_1[] = {12, 24, 36, 48};
	
	/* Shows the students that sizeof() works with static arrays */
	long unsigned int stat_arr_len = sizeof( array_1 )/sizeof( int );

	/* Strict Dynamic Memory Allocation on the Data Heap */
	/* Must define the size since sizeof() can't be called Heap data */
	long unsigned int dyn_arr_len = 4;
	int* dynamic_array = (int *)malloc( dyn_arr_len * sizeof(int) );
	
	/* Shows students we need stricter allocation with dynamic arrays */
	*( (int *)( (void *)dynamic_array ) ) = 9;
	*( (int *)( (void *)dynamic_array + 1*sizeof(int) ) ) = 18;
	*( (int *)( (void *)dynamic_array + 2*sizeof(int) ) ) = 27;
	*( (int *)( (void *)dynamic_array + 3*sizeof(int) ) ) = 36;	

	/* Function Call */
	fprintf( stdout, "Total sum = %d\n", 
		print_arrays( array_1, stat_arr_len, dynamic_array, dyn_arr_len ) );

	return 0;
}
