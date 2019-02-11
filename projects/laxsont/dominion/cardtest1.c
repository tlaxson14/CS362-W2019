/****************************************
* NAME: Travis Laxson
* DATE: 07 Feb 2019
* DESCRIPTION: Unit testing file for the
  refactored Smithy action game card from
  the dominion.c source code.
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dominion.h"
#include "rngs.h"

/* Function declarations */
int smithy_function(struct gameState *state, int currentPlayer, int handPos);


int main(void)
{
  printf("-----------------\n-  CARD TEST 1  -\n-  SMITHY CARD  -\n-----------------\n\n");

  /* Create new game instance with kingdom cards */
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
                          remodel, smithy, village, baron, great_hall};
  /* Number of players */
  int players = 2;

  /* Seed value */
  int seed = 1000;

  /* New gamestate */
  struct gameState state;

  /* Initialize new game */
  initializeGame(players, kingdomCards, seed, &state);

  /* Assign opening hand with Smithy card */
  state.hand[0][0] = smithy;
  state.handCount[0] = 1;

  /* Assert proper hand initialized correctly */
  if(cardEffect(smithy, -1, -1, -1, &state, 0, 0) == 0)
    printf("Smithy in hand.\n\n");
  else
    printf("Smithy NOT in hand.\n\n");

  /* Test condition: Test for accurate card functionality (+3 cards) */
  if(state.handCount[0] == 3)
    printf("Card functions correctly!\nCards added: %d\n\n", state.handCount[0]);
  else
    printf("Card functions incorrectly!\nCards added: %d\n\n", state.handCount[0]);

  printf("------------------\n CARD TEST PASSED \n------------------\n\n");

  return 0;
}
