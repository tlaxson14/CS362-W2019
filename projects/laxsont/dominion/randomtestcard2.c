/*****************************************
* Name: Travis Laxson
* ONID: laxsont
* Date: 27 Feb 2019
* Description:
	Source file containing the random
	testing logic for the Village card
	from the Dominion game.
* Sources:
	CPU time: https://stackoverflow.com/questions/5248915/execution-time-of-c-program
	
******************************************/  
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include "rngs.h"

/* Global constants */
#define N 500		/* NUMBER OF TESTS */


/* Function declarations */
void randomTestVillageCard(void);


int main() 
{
	double executionTime;
	clock_t startTimer;
	clock_t endTimer;

	/* Seed random value */
	srand(time(NULL));

	/* TEST: Get start CPU time to execute random tester */
	startTimer = clock();

	printf("-----------------\n-  RANDOM TEST  -\n- VILLAGE CARD  -\n-----------------\n");   
	
	/* Execute Smithy card test N number of times */ 
        randomTestVillageCard();

	/* TEST: Get end CPU time to execute random tester */
	endTimer = clock();

	/* Calculate delta for total CPU execution time */
	executionTime = (double)(endTimer - startTimer) / CLOCKS_PER_SEC;

	/* Display test results */
   	printf("\nCompleted tests: %d\n", N);
	printf("CPU execution time: %f\n\n", executionTime);

	return 0;
}

/*******************************************************
	RANDOM TESTER FOR VILLAGE CARD FUNCTION
********************************************************
NAME:
	randomTestVillageCard	
DESCRIPTION:
	Iterates over N number of test cases in which 
INPUT:
	N/A
OUTPUT:
	N/A
SOURCES:

********************************************************/
void randomTestVillageCard()
{
	printf("Inside test village fcn\n");





}
