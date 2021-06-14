////////////////////////////////////////////////////////////////////////////////
// Main File:        division.c
// This File:        division.c
// Other Files:      intdate.c, sendsig.c
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
#include <signal.h>
#include <string.h>

int cnt;

/* signal handler of SIGFPE */
void handler_SIGFPE()
{
	fprintf(stderr, "Error: a division by 0 operation was attempted.\n");
	printf("Total number of operations completed successfully: %i\n\
The program will be terminated.\n", cnt);
	exit(0);
}
/* signal handler of SIGINT */
void handler_SIGINT()
{
	printf("\nTotal number of operations successfully completed: %i\n\
The program will be terminated.\n", cnt);
	exit(0);
}

/* Receiving two ints and do division and setting signal handlers
 *
 * return 0
 */
int main()
{
	struct sigaction act; //used to register signal handlers
	memset(&act, 0, sizeof(act));
	act.sa_handler = handler_SIGFPE;
	if(sigaction(SIGFPE, &act, NULL) != 0)
	{
		printf("Error: registering SIGFPE\n");
		exit(1);
	}
	memset(&act, 0, sizeof(act));
	act.sa_handler = handler_SIGINT;
	if(sigaction(SIGINT, &act, NULL) != 0)
	{
		printf("Error: registering SIGINT\n");
		exit(1);
	}
	char input[100];
	int a = 0, b = 0, c = 0, d = 0;
	while(1)
	{
		printf("Enter first integer: ");
		fgets(input, 100, stdin);
		a = atoi(input);
		printf("Enter second integer: ");
		fgets(input, 100, stdin);
		b = atoi(input);
		c = a/b;
		d = a%b;
		printf("%i / %i is %i with a remainder of %i\n", a, b, c, d);
		cnt ++;
	}
	return 0;
}
