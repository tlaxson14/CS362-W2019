/*****************************************
* Name: Travis Laxson
* ONID: laxsont
* Date: 27 Feb 2019
* Description:
	Source file containing the random
	testing logic for the Adventurer card
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
void randomTestAdventurerCard(void);


int main() 
{
	double executionTime;
	clock_t startTimer;
	clock_t endTimer;

	/* Seed random value */
	srand(time(NULL));

	/* TEST: Get start CPU time to execute random tester */
	startTimer = clock();

	printf("-----------------\n-  RANDOM TEST  -\n ADVENTURER CARD \n-----------------\n");   
	
	/* Execute Smithy card test N number of times */ 
        randomTestAdventurerCard();

	/* TEST: Get end CPU time to execute random tester */
	endTimer = clock();
	
	/* Calculate delta for total CPU execution time */
	executionTime = (double)(endTimer - startTimer) / CLOCKS_PER_SEC;

	/* Display test results */
   	printf("\nCompleted tests: %d\n", N);
	printf("CPU execution time: %f\n\n", executionTime);

	return 0;
}

/********************************************************
	RANDOM TESTER FOR ADVENTURER CARD FUNCTION
*********************************************************
NAME:
	randomTestAdventurerCard	
DESCRIPTION:
	Iterates over N number of test cases in which 
INPUT:
	N/A
OUTPUT:
	N/A
SOURCES:
	Random algorithm - https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
********************************************************/
void randomTestAdventurerCard()
{
	bool numActionsResult, handCountResult, deckCountResult, discardCountResult;
	int i, player, numPlayers, testGameState;
	int seed = 1000;
	int failCount = 0, passCount = 0;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState state;
	struct gameState temp;

	/* Run random tests n number of times */
	for(i=0; i < N; i++){
		
		/* Print test number */
		printf(" -- Test No.%d --\n", i+1);
	}
}
