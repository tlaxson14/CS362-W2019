/****************************************
* NAME: Travis Laxson
* DATE: 08 Feb 2019
* DESCRIPTION: Unit testing file for the
  refactored Village action game card from
  the dominion.c source code.
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
int village_function(struct gameState *state, int currentPlayer, int handPos);

int main ()
{
  int players = 2;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
                          remodel, smithy, village, baron, great_hall};
	int seed = 1000;
  int startHandCount = 0;
  bool passed;

  printf("\n-----------------\n-  CARD TEST 3  -\n  VILLAGE CARD  \n-----------------\n\n");

	/* Create new game instance and initialize */
	struct gameState* state = malloc(sizeof(struct gameState));
	initializeGame(players, kingdomCards, seed, state);

  /* Assign starting hand count */
	startHandCount = state->handCount[0];

  /* Print starting hand count vs. expected hand count */
  printf("Hand count: %d\nExpected hand count: %d\n\n", startHandCount, state->handCount[0]);

  /* Village function call passing parameters */
	village_function(state, 0, 2);

  /* Check conditions for starting hand count to pass test */
  if(startHandCount == state->handCount[0])
    passed = true;
  else
    passed = false;

  /* Print whether card test passed or failed based on boolean var value */
  if(passed)
    printf("------------------\n CARD TEST PASSED \n------------------\n");
  else
    printf("------------------\n CARD TEST FAILED \n------------------\n");

  return 0;
}
