/****************************************
* NAME: Travis Laxson
* DATE: 10 Feb 2019
* DESCRIPTION: Functional unit testing file
  for testing the fullDeckCount function
  found in the dominion.c source code.
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/* Boolean values */
typedef enum {false = 0, true = 1} bool;

int main()
{
  bool passed;
  int i, j, game, testgame;
  int passedCount = 0;
  int players = 2;
  int iterations = 50; /* Number of times to run loop */
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
                          remodel, smithy, village, baron, great_hall};
  int seed = 1000;
  struct gameState state;
  struct gameState testState;

  printf("\n-----------------\n-  UNIT TEST 4  -\n fullDeckCount() \n-----------------\n");

  /* Initialize game */
	initializeGame(players, kingdomCards, seed, &state);
	for(i=0; i < players; i++) {
    printf("\n** fullDeckCount Function Test %d **\nPlayer %d\n", i+1, i+1);

    /* Test for desired number of iterations */
    for(j=0; j < iterations; j++) {
      game = fullDeckCount(players, kingdomCards, &state);
      testgame = fullDeckCount(players, kingdomCards, &testState);
      if(game == testgame) {
        passed = true;
        passedCount++;
      }
      else
        passed = false;
    }
    if(passed) {
      printf("Test Result: Pass\n");
    }
    else
      printf("Test Result: Fail\n");
  }

  /* Normalize the passedCount */
  passedCount = passedCount / 2;

  /* Output status of test */
  if(passedCount == iterations)
    printf("\n------------------\n UNIT TEST PASSED \n------------------\n");
  else
    printf("\n------------------\n UNIT TEST FAILED \n------------------\n");

  return 0;
  }
