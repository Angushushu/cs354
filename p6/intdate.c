////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
// Other Files:      sendsig.c, division.c
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
#include <unistd.h>
#include <time.h>

int cnt = 0;

/* signal handler of SIGALRM */
void handler_SIGALRM()
{
	pid_t pid = getpid();
	time_t t;
    time(&t);
    printf("PID: %i | Current Time: %s", pid, ctime(&t));
	alarm(3);
}
/* signal handler of SIGUSR1 */
void handler_SIGUSR1()
{
	cnt ++;
	printf("SIGUSR1 caught!\n");
}
/* signal handler of SIGINT */
void handler_SIGINT()
{
	printf("\nSIGINT received.\nSIGUSR1 was received %i times. Exiting now.\n", cnt);
	exit(0);
}

/* Keep setting alarm and register signal handlers
 *
 * return 0
 */
int main()
{
	struct sigaction act; //used to register signal handlers
	memset(&act, 0, sizeof(act));
	act.sa_handler = handler_SIGALRM;
	if(sigaction(SIGALRM, &act, NULL) != 0)
	{
		printf("Error: registering SIGALRM\n");
		exit(1);
	}
	memset(&act, 0, sizeof(act));
	act.sa_handler = handler_SIGUSR1;
	if(sigaction(SIGUSR1, &act, NULL) != 0)
	{
		printf("Error: registering SIGUSR1\n");
		exit(1);
	}
	memset(&act, 0, sizeof(act));
	act.sa_handler = handler_SIGINT;
	if(sigaction(SIGINT, &act, NULL) != 0)
	{
		printf("Error: registering SIGUSR1\n");
		exit(1);
	}
	printf("Pid and time will be printed every 3 seconds.\n\
Enter ^C to end the program.\n");
    alarm(3);
	while(1);
	return 0;
}
