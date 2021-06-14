////////////////////////////////////////////////////////////////////////////////
// Main File:        cache1D.c
// This File:        cache1D.c
// Other Files:      cache2Drows.c and cache2Dcols.c
// Semester:         CS 354 Spring 2019
//
// Author:           Shu Hu
// Email:            shu94@wisc.edu
// CS Login:         shuh
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          none
//
// Online sources:   none
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>

//global array
int arr[100000];

/* This function set all elt in array as the index
 *
 * No parameter
 * return 0
 */
int main(){
	for(int i=0; i<100000; i++)
		arr[i] = i;
	return 0;
}
