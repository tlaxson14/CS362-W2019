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
	Random algorithm - https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
********************************************************/
void randomTestVillageCard()
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
		
		/* Initialize random game conditions algorithm */
		/* Get random number of players between 2-4 */
		numPlayers = 2 + rand() / (RAND_MAX / (4 - 2 + 1) + 1);
		printf("Num players = %d\n", numPlayers);
		assert(numPlayers > 0);		

		/* Get random player (2-4 from which to run tests */
		player = 2 + rand() / (RAND_MAX / (4 - 2 + 1) + 1);
		printf("Player selected = Player %d\n", player);
		assert(player >= 2 && player <= 4);		

		/* Init game state */
		testGameState = initializeGame(numPlayers, kingdomCards, seed, &state);		
		printf("Gamestate = %d\n", testGameState);
		assert(testGameState == 0);		

		/* Assign whose turn */ 
		state.whoseTurn = player;

		/* Assign random number of actions, buys, and coins to player */	
		state.numActions =  rand() % 7; /*rand() / (RAND_MAX / (6 + 1) + 1);*/
		state.coins = rand() % 7; /*rand() / (RAND_MAX / (6 + 1) + 1);*/
		state.numBuys = rand() % 7; /*/ (RAND_MAX / (6 + 1) + 1);*/

		/* Give player village card */
		state.hand[player][0] = kingdomCards[7];
		assert(kingdomCards[7] == village);

		/* Give player random hand count */
		state.handCount[player] = rand() % MAX_HAND;/*rand() / (RAND_MAX / (MAX_HAND + 1) + 1.0);*/
		printf("HandCount = %d\n", state.handCount[player]);
		/*assert(state.handCount[player] >= 0);*/
		
		/* Give player random deck count */
		state.deckCount[player] = rand() % MAX_DECK;/*rand() / (RAND_MAX / (MAX_DECK + 1) + 1);*/
		printf("DeckCount = %d\n", state.deckCount[player]);
		assert(state.deckCount[player] >= 0);/* && state.deckCount[player] <= MAX_HAND);*/

		/* Give player random discard count */
		state.discardCount[player] = rand() % MAX_DECK;/*rand() / (RAND_MAX / (MAX_DECK + 1) + 1);*/
		printf("discardCount = %d\n", state.discardCount[player]);
		assert(state.discardCount[player] >= 0);/* && state.discardCount[player] <= MAX_HAND);*/
		
		/* Save game state to temp in order to compare different game states */
		memcpy(&temp, &state, sizeof(struct gameState));

		/* Play test card */
		cardEffect(village, 0, 0, 0, &state, 0, 0);

		/* Assert and validate number of actions between game states */		
		assert(state.numActions == temp.numActions + 2);
		if(state.numActions == temp.numActions + 2){
			printf("Test result: Number of actions PASSED! State: %d - Temp: %d\n", state.numActions, temp.numActions+2);
			passCount++;
			numActionsResult = true;
		}
		else{
			failCount++;
			numActionsResult = false;
		}
		
		/* Assert and validate hand count of player */
		assert(state.handCount[player] == temp.handCount[player]);
		if(state.handCount[player] == temp.handCount[player]){
			printf("Test result: Hand count test PASSED! State: %d - Temp: %d\n", state.handCount[player], temp.handCount[player]);
			passCount++;
			handCountResult = true;
		}
		else{
			printf("Test result: Hand count test FAILED! State: %d - Temp: %d\n", state.handCount[player], temp.handCount[player]);
			failCount++;
			handCountResult = false;
		}

		/* Assert and validate deck count of player */
		/*assert(state.deckCount[player] == temp.deckCount[player]-1);
		*/
		if(state.deckCount[player] == temp.deckCount[player]-1){
			printf("Test result: Deck count test PASSED! State: %d - Temp: %d\n", state.deckCount[player], temp.deckCount[player]);
			passCount++;
			deckCountResult = true;
		}
		else{
			printf("Test result: Deck count test FAILED! State: %d - Temp: %d\n", state.deckCount[player], temp.deckCount[player]);
			failCount++;
			deckCountResult = false;
		}
		
		/* Assert and validate discard count of player */
/*		assert(state.discardCount[player] == temp.discardCount[player]);
*/
		if(state.discardCount[player] == temp.discardCount[player]){
			printf("Test result: Deck count test PASSED! State: %d - Temp: %d\n", state.discardCount[player], temp.discardCount[player]);
			passCount++;
			discardCountResult = true;
		}
		else{
			printf("Test result: Deck count test FAILED! State: %d - Temp: %d\n", state.discardCount[player], temp.discardCount[player]);
			failCount++;
			discardCountResult = false;
		}
		
		/* Print testing results */
		printf("\n---------------------------\n- Random Testing Results -\nPASSED TESTS: %d\nFAILED TESTS: %d\n---------------------------\n", passCount, failCount);
		
	}
}
