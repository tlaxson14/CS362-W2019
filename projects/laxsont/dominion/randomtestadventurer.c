/*****************************************
* Name: Travis Laxson
* ONID: laxsont
* Date: 28 Feb 2019
* Description:
	Source file containing the random
	testing logic for the Adventurer card
	from the Dominion game.
* Sources:
	CPU time: https://stackoverflow.com/questions/5248915/execution-time-of-c-program
	Memcpy: http://man7.org/linux/man-pages/man3/memcpy.3.html
	Randomness algorithm: https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand 
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
#define N 1000				/* NUMBER OF TESTS */

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

	/* Display CPU clock test results */
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
	a dominion game is randomized and initalized 
	to test the adventurer game card. 
INPUT:
	N/A
OUTPUT:
	Displays debugging printf statements and 
	also prints out the results of the automated
	random testing
SOURCES:
	Random algorithm - https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
	Memcpy - http://man7.org/linux/man-pages/man3/memcpy.3.html
	
********************************************************/
void randomTestAdventurerCard()
{
	int i, numPlayers, bonus, choice1, choice2, choice3, handPos, card1, card2;
	int player = 0, failed = 0, passed = 0;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};

	/* Run random tests n number of times */
	for(i=0; i < N; i++){
	
		/* Initialize game states for testing */
        	struct gameState state;
		struct gameState copy;

		/* Print test number */
		printf(" -- Test No.%d --\n", i+1);
		
		/* Get random number of players 2-4 */
        	numPlayers = 2 + rand() / (RAND_MAX / (MAX_PLAYERS - 2 + 1) + 1); 
		
		/* Initialize game with random seed */
		initializeGame(numPlayers, kingdomCards, rand(), &state);
		
		/* Get random player from number of players */
		player = rand() % numPlayers;

		/* Assign player turn */
        	state.whoseTurn = player;

        	handPos = rand() % MAX_HAND;
       		bonus = rand() % 50;
        	choice1 = rand() % 50;
        	choice2 = rand() % 50;
        	choice3 = rand() % 50;

		/* Copy current game state to a copy state */
        	memcpy(&copy, &state, sizeof(struct gameState));

		/* Play card and get effects of adventurer */
        	cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);

		/* Test if copy state and game state hand counts are different by +2 cards */
        	if(state.handCount[player] != copy.handCount[player] + 2){
            		printf("TEST FAILED! Drawn cards not equal to 2!\n");
            		failed++;
        	}
		else{
            		printf("TEST PASSED! Drawn cards equal to 2!\n");
			passed++;
		}

		/* Test logic for the first card drawn by the player after playing adventurer */
        	card1 = state.hand[player][state.handCount[player] - 1];
        	if(card1 != copper && card1 != silver && card1 != gold){
            		printf("TEST FAILED! Drawn card1 is not a treasure card.\n");
            		failed++;
        	}
		else{
            		printf("TEST PASSED! Drawn card1 is a treasure card!\n");
			passed++;
		}

		/* Test logic for the second card drawn by the player after playing adventurer */
        	card2 = state.hand[player][state.handCount[player] - 2];
        	if(card2 != copper && card2 != silver && card2 != gold){
            		printf("TEST FAILED! Drawn card2 is not a treasure card.\n");
            		failed++;
        	}
		else{
            		printf("TEST PASSED! Drawn card2 is a treasure card!\n");
			passed++;
    		}
	}

	/* Print testing results */
	printf("\n---------------------------\n- Random Testing Results -\nPASSED TESTS: %d\nFAILED TESTS: %d\n---------------------------\n", passed, failed);
}

