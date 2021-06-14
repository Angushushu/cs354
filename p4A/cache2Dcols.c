////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Dcols.c 
// This File:        cache2Dcols.c
// Other Files:      cache1D.c and cache2Drows.c
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

/* This function set all elt in array as the index
 *
 * No parameter
 * return 0
 */
int main(){
	for(int j=0; j<500; j++)
		for(int i=0; i<3000; i++)
			arr2D[i][j] = j + i;
	return 0;
}
