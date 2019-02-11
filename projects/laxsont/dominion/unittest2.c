/****************************************
* NAME: Travis Laxson
* DATE: 09 Feb 2019
* DESCRIPTION: Functional unit testing file
  for testing the whoseTurn function
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

int main(){
  bool passed;

  /* New gamestate */
  struct gameState state;

  /* Initialize numPlayers and whose turn */
  state.numPlayers = 4;
  state.whoseTurn = 2;

  printf("\n-----------------\n-  UNIT TEST 2  -\n-  whoseTurn() -\n-----------------\n");

  /* Display values */
  printf("\n** whoseTurn Function Test 1 **\nNumber of players: %d\nCurrent turn: %d\nExpected turn: %d\n", state.numPlayers, whoseTurn(&state), whoseTurn(&state));

  /* Test whose turn with hard coded value */
  if(whoseTurn(&state) == 2)
    passed = true;
  else
    passed = false;

  /* Output status of test */
  if(passed)
    printf("\n------------------\n UNIT TEST PASSED \n------------------\n");
  else
    printf("\n------------------\n UNIT TEST FAILED \n------------------\n");

  return 0;
}
