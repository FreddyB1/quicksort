/********************************************
	Non-recursive implementation of the quicksort algorithm.
	Available at:

	http://alienryderflex.com/quicksort/


********************************************/

/********************************************

				Natives

********************************************/

/* quicksort_asc(array[], elements = sizeof(array));
	
	Sorts a single dimension array in ascending order.
	
	* Returns 
	 	- 0: function failed to execute
	 	- 1: function executed successfully

	* params
		- array[]: the array you desire to sort.
		- elements: the number of elements starting at index 0 that you wish to sort. (not final index).

*/
native quicksort_asc(array[], elements = sizeof(array));

/* quicksort_desc(array[], elements = sizeof(array));
	
	Sorts a single dimension array in descending order.
	
	* Returns 
	 	- 0: function failed to execute.
	 	- 1: function executed successfully.

	* params
		- array[]: the array you desire to sort.
		- elements: the number of elements starting at index 0 that you wish to sort (not final index).

*/

native quicksort_desc(array[], elements = sizeof(array));





/********************************************

				Useful Macros 

********************************************/

/* quicksort_ascEx(array[], start, end);
	
	Sorts a single dimension array in ascending order starting at a specific index.
	
	* Returns 
	 	- 0: function failed to execute
	 	- 1: function executed successfully

	* params
		- array[]: the array you desire to sort.
		- start: the starting index
		- end: the final index

*/
#define quicksort_ascEx(%0,%1,%2) 	(quicksort_asc(%0[%1],%2-%1+1))

/* quicksort_descEx(array[], start, end);
	
	Sorts a single dimension array in descending order starting at a specific index.
	
	* Returns 
	 	- 0: function failed to execute
	 	- 1: function executed successfully

	* params
		- array[]: the array you desire to sort.
		- start: the starting index
		- end: the final index

*/
#define quicksort_descEx(%0,%1,%2)  (quicksort_desc(%0[%1],%2-%1+1))
