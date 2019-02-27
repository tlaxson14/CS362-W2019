/*****************************************
* Name: Travis Laxson
* ONID: laxsont
* Date: 26 Feb 2019
* Description:
	Source file containing the random
	testing logic for the smithy card
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
#include "rngs.h"

/* Global constant */
#define N 50000

/* Function declaration */
void randomTestSmithyCard();

int main() 
{
	int i = 0;		/* Loop counter */
	int pass = 0;		/* Pass count var */
	int fail = 0;		/* Fail count var */
	
	/* Seed random value */
	srand(time(NULL));

	/* TEST: Get start CPU time to execute random tester */
	clock_t startTimer = clock();

	printf("-----------------\n-  RANDOM TEST  -\n-  SMITHY CARD  -\n-----------------\n");   
	
	/* Execute Smithy card test N number of times */ 
	while(i < N){
        	randomTestSmithyCard();
		i++;
    	}

	/* TEST: Get end CPU time to execute random tester */
	clock_t endTimer = clock();

	/* Calculate delta for total CPU execution time */
	double executionTime = (double)(endTimer - startTimer) / CLOCKS_PER_SEC;

	/* Display test results */
   	printf("\nCompleted tests: %d\n", N);
	printf("CPU execution time: %f\n\n", executionTime);

	return 0;
}

/*******************************************************
	RANDOM TESTER FOR SMITHY CARD FUNCTION
********************************************************
NAME:
	randomTestSmithyCard	
DESCRIPTION:
	Iterates over N number of test cases in which 
INPUT:
	N/A
OUTPUT:
	N/A
SOURCES:
********************************************************/
void randomTestSmithyCard()
{
	printf("");
}
