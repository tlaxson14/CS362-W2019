/****************************************
* NAME: Travis Laxson
* DATE: 08 Feb 2019
* DESCRIPTION: Unit testing file for the
  refactored Council Room action game card
  from the dominion.c source code.
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dominion.h"
#include "rngs.h"

/* Boolean variable typedef */
typedef enum {false = 0, true = 1} bool;

/* Function declaration */
int council_room_function(struct gameState *state, int handPos);

int main ()
{
	int i, player1, player2;
	int seed = 1000;
	int players = 2;
	int r, handCount, handPos, councilRoomHandPos, origP1HandCount, origP2HandCount;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
                          remodel, smithy, village, baron, great_hall};
  int failCount = 0;
  struct gameState state;

  /* Clear new gamestate and initialize new game */
	memset(&state, 23, sizeof(struct gameState));
	r = initializeGame(players, kingdomCards, seed, &state);

  /* Initialize test conditions with hand position and number of cards in hand */
	handPos = 4;
	handCount = 3;

  /* Initialize deck counts and players */
	state.deckCount[1] = 100;
	state.deckCount[2] = 100;
	state.deckCount[3] = 100;
	state.handCount[1] = 5;
	state.handCount[2] = 5;
	state.handCount[3] = 5;
	player1 = 1;
	player2 = 2;

  /* Initialize council room position in hand and set original player handcounts */
  councilRoomHandPos = 4;
	origP1HandCount = 0;
	origP2HandCount = 0;

  printf("\n-----------------\n-  CARD TEST 4  -\nCOUNCIL ROOM CARD \n-----------------\n");


/* Iterate through the card for each player and test if council card given and number of cards drawn */
	for(i=0; i < players; i++) {

     printf ("\nPLAYER %d\n-----------------\nCard given passed!\nPlayer %d has obtained the Council Room card.\n", i+1, i+1);

     /* Initialize hand counts */
     origP1HandCount = state.handCount[player1-1];
	   origP2HandCount = state.handCount[player2-1];

	    /* Call council room function passing the game state and hand position of the council room card */
     council_room_function(&state, councilRoomHandPos);

     if((i == player1-1 && origP1HandCount == state.handCount[player1-1]-3 ) || (i == player1-1 && origP1HandCount == state.handCount[player1-1]-1 ) || (origP1HandCount == state.handCount[player1-1]-3) || (origP1HandCount == state.handCount[player1-1]-1))
		     printf("\nHand count test passed!\nPlayer %d hand count: %d\nPlayer %d expected hand count: %d\n", i+1, state.handCount[0], i+1, state.handCount[0]);
	   else {
		     if(i == 0) {
			        printf("\nHand count test failed!\nPlayer %d hand count: %d\nPlayer %d expected hand count: %d\n", i+1, state.handCount[0], i+1, state.handCount[0] + 3);
			        failCount++;
		     }
         else {
			        printf("\nHand count test failed!\nPlayer %d hand count: %d\nPlayer %d expected hand count: %d\n", i+1, state.handCount[0], i+1, state.handCount[0] + 1);
			        failCount++;
         }
      }

    /* Test for right number of cards in hand */
  	 if((i == player2-1 && origP2HandCount == state.handCount[player2-1]-3 ) || (i == player2-1 && origP2HandCount == state.handCount[player2-1]-1 ) || (origP2HandCount == state.handCount[player2-1]-3) || (origP2HandCount == state.handCount[player2-1]-1))
		  printf("\nCard count test passed!\nPlayer %d card count: %d\nPlayer %d expected card count: %d\n\n", i+1, state.handCount[1], i+1, state.handCount[1]);
	   else {
		     if(i == 0) {
			        printf("\nCard count test failed!\nPlayer %d card count: %d\nPlayer %d expected card count: %d\n\n", i+1, state.handCount[1], i+1, state.handCount[1] + 3);
			        failCount++;
         }
         else {
          printf("\nCard count test passed!\nPlayer %d card count: %d\nPlayer %d expected card count: %d\n\n", i+1, state.handCount[1], i+1, state.handCount[1] + 1);
     			failCount++;
         }
			}
	}

  memset(&state, 23, sizeof(struct gameState));   // clear the game state
  	r = initializeGame(players, kingdomCards, seed, &state); // initialize a new game

  	handPos = 4; 		// used to hold the location of council_room
  	handCount = 3;		// Used to set the number of cards

  	state.deckCount[1] = 100;
  	state.deckCount[2] = 100;
  	state.deckCount[3] = 100;

  	state.handCount[1] = 5;
  	state.handCount[2] = 5;
  	state.handCount[3] = 5;

  	player1 = 1;
  	player2 = 2;

  councilRoomHandPos = 4;

  if(failCount == 0)
    printf("------------------\n CARD TEST PASSED \n------------------\n");
	else
		printf("------------------\n CARD TEST FAILED \n------------------\n");

	return 0;

}
