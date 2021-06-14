////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Drows.c
// This File:        cache2Drows.c
// Other Files:      cache1D.c and cache2Dcols.c
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

// A global 2D array
int arr2D[3000][500];

/* This function set all elt in 2D array as row number + col number
 *
 * No parameter
 * return 0
 */
int main(){
	for(int i=0; i<3000; i++)
		for(int j=0; j<500; j++)
			arr2D[i][j] = i + j;
	return 0;
}
