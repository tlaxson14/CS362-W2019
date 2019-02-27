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
#include <math.h>
#include "rngs.h"

/* Global constants */
#define N 500

/* Function declaration */
void randomTestSmithyCard();
void executeSmithyCardCheck(int, struct gameState*);


int main() 
{
	double executionTime;
	clock_t startTimer;
	clock_t endTimer;

	/* Seed random value */
	srand(time(NULL));

	/* TEST: Get start CPU time to execute random tester */
	startTimer = clock();

	printf("-----------------\n-  RANDOM TEST  -\n-  SMITHY CARD  -\n-----------------\n");   
	
	/* Execute Smithy card test N number of times */ 
        randomTestSmithyCard();

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
	Random() - https://stackoverflow.com/questions/42459820/how-to-use-random-in-c
		   https://stackoverflow.com/questions/2509679/how-to-generate-a-random-integer-number-from-within-a-range
	Floor() - https://www.geeksforgeeks.org/ceil-floor-functions-cpp/
	
********************************************************/
void randomTestSmithyCard()
{
	int i, player;
	int total = 0, j = 0;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState state;
	

	int totalFailed = 0;
	int cardEffectResult, discardCardResult, drawCardResult, deckHandCountResult;
	int failedCardEffect = 0, failedDiscardCard = 0, failedDrawCard = 0, failedDeckHandCount = 0;
	int cardDraw1, cardDraw2, cardDraw3;
	struct gameState temp;

	/* Iterate through N number of random tests */
	for(i=0; i < N; i++){
		
		/* Create randomized game state */
		while(j < sizeof(struct gameState)){
			((char*)&state)[j] = floor(Random() * 256);
			j++;
		}
	
		/* Randomly select player values */
		player = floor(Random() * MAX_PLAYERS);
		
		/* Assign players turn */
		state.whoseTurn = player;
		
		/* Assign random values for gameplay cards played */
		state.playedCardCount = floor(Random() * (MAX_DECK-1));

		/* Assign random handcount to player */
		state.handCount[player] = floor(Random() * MAX_HAND);

		/* Assign random deck count to player */
		state.deckCount[player] = floor(Random() * MAX_DECK);

		/* Assign random discard count to player */
		state.discardCount[player] = floor(Random() * MAX_DECK);

		/* DEBUG: Print test num */
		printf("Test %d: \n", i+1);

		/* Save current gamestate to the temp gamestate */
		memcpy(&temp, &state, sizeof(struct gameState));

		/* Run cardEffect function and assign return value result */
		cardEffectResult = cardEffect(smithy, 0, 0, 0, &state, 0, 0);

		/* Check the returned result of the cardEffect function */
		if(cardEffectResult)
			failedCardEffect += 1;		

		/* Check the returned result of the discardCard function */
		discardCardResult = discardCard(0, player, &temp, 0);
	
		/* Check the returned result of the discardCard function */
		if(discardCardResult)
			failedDiscardCard += 1;		
		 
		/* Draw 3 cards */
		cardDraw1 = drawCard(player, &temp);
		cardDraw2 = drawCard(player, &temp);
		cardDraw3 = drawCard(player, &temp);

		/* Check returned results of drawCard function, if error add to error count */
		if(temp.deckCount[player] != 0){
			/* Check all three cards drawn for errors */
			if(cardDraw1 == -1)
				failedDrawCard += 1;
			if(cardDraw2 == -1)
				failedDrawCard += 1;
			if(cardDraw3 == -1)
				failedDrawCard += 1;
	}
	
		/* Check the hand count and deck count for the current state of the game for the player */
		if(!(state.handCount[player] == temp.handCount[player] && state.deckCount[player] == temp.deckCount[player]))
			/* Increment failed deck hand count */
			failedDeckHandCount++;
	
			/* Calc total number of failed tests */
			totalFailed = failedCardEffect + failedDiscardCard + failedDrawCard + failedDeckHandCount;

		/* Print calculated results of tests */
	  	printf("---------------\n RANDOM CARD TEST RESULTS \n--------------\n");
		printf("Total Failed: %d\n", totalFailed);
		printf("cardEffect Failed: %d\n", failedCardEffect);
		printf("discardCard Failed: %d\n", failedDiscardCard);
		printf("drawCard Failed: %d\n", failedDrawCard);
		printf("deckCount Failed: %d\n", failedDeckHandCount);

		/* Call function to check the random instance for player card and game scenario */
	/*	executeSmithyCardCheck(player, &state);	*/

	}
}

/*******************************************************
    RANDOM SMITHY CARD CHECK IMPLEMENTATION FUNCTION   
********************************************************
NAME:
	executeSmithyCardCheck	
DESCRIPTION:
	 
INPUT:
	N/A
OUTPUT:
	N/A
SOURCES:
	Memcpy - https://www.geeksforgeeks.org/memcpy-in-cc/
		 http://man7.org/linux/man-pages/man3/memcpy.3.html
********************************************************/
void executeSmithyCardCheck(int player, struct gameState* state)
{
	printf("Inside helper\n");


}





