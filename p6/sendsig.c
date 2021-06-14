////////////////////////////////////////////////////////////////////////////////
// Main File:        sendsig.c
// This File:        sendsig.c
// Other Files:      intdate.c, division.c
// Semester:         CS 354 Spring 2019
//
// Author:           Shu
// Email:            shu94@wisc.edu
// CS Login:         shuh
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          none
//
// Online sources:   google
//
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/* Send SIGUSR1 or SIGINT to a proc
 *
 * argc, count the number of arguments
 * argv, the array of arguments
 * return 0
 */
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "Usage: <signal type> <pid>\n");
		exit(1);
	}
	pid_t pid = (pid_t)(atoi(argv[2]));
	if(strcmp(argv[1], "-u") == 0)
		kill(pid, 10);
	if(strcmp(argv[1], "-i") == 0)
		kill(pid, 2);
	return 0;
}