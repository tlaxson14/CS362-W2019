/****************************************
* NAME: Travis Laxson
* DATE: 09 Feb 2019
* DESCRIPTION: Functional unit testing file
  for testing the isGameOver() function
  found in the dominion.c source code.
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main ()
{
  int i, n, r;
  int players = 2;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
                          remodel, smithy, village, baron, great_hall};
	int seed = 1000;
  int startHandCount = 0;
  int failCount = 0;
  struct gameState state;

  printf("\n-----------------\n-  UNIT TEST 1  -\n-  isGameOver() -\n-----------------\n");

  /* Clear new gamestate and initialize new game */
	memset(&state, 23, sizeof(struct gameState));
	r = initializeGame(players, kingdomCards, seed, &state);

  state.supplyCount[province] = 15;

  /* First test: Game ends if province counter equals zer0 */
  /* Begin at supplyCount[province] value and countdown until zero */
	printf("\n** isGameOver Function Test 1 **\nGame ends when province equals zero.\nCountdown starts at %d.\n\n", state.supplyCount[province]);
  /* Begin countdown */
  for(i=state.supplyCount[province]; i >= 0; i--) {
    state.supplyCount[province] = i;
		n = isGameOver(&state);
    if (n == 0)
			printf("Test passed! Game not over. Province count = %d\n----------\n", state.supplyCount[province]);
		else if (i == 0 && n == 1)
			printf("isGameOver function unit test passed!\nGame over.\nProvince count = %d\n----------\n", state.supplyCount[province]);
		else if (i == 0 && n == 0){
      printf("isGameOver function unit test failed!\nGame not over.\nProvince count = %d\n----------\n", state.supplyCount[province]);
      failCount++;
    }
		else {
			printf("isGameOver function unit test failed!\nGame not over.\nProvince count = %d\n----------\n", state.supplyCount[province]);
			failCount++;
		}
	}

	/* Hard coded value of province cards */
	state.supplyCount[province] = 5;

  printf("\n** isGameOver Function Test 2 **\nIf supplyCount i-th index equals zero for n times then the game is over.\n");
  /* Run until i-th index is zero n number of times */
  while(n < 50) {
    state.supplyCount[n] = 0;
    if(n < 2) {
			i = isGameOver(&state);
      if(i == 0)
        printf("\n----------\nisGameOver function unit test passed!\nGame continues..\nsupplyCount = %d\n", n+1);
      else {
        printf("\n----------\nisGameOver function unit test failed! Game did not end.\nsupplyCount = %d\n", n+1);
        failCount++;
      }
    }
    else {
      i = isGameOver(&state);
      if(i == 1)
        printf("\n----------\nisGameOver function unit test passed!\nGame over.\nn = %d.\n", n+1);
      else {
        printf("\n----------\nisGameOver function unit test failed! Game did not end.\nsupplyCount = %d.\n", n+1);
        failCount++;
      }
    }
    n++;
  }

  if(failCount == 0)
    printf("------------------\n UNIT TEST PASSED \n------------------\n");
	else
		printf("------------------\n UNIT TEST FAILED \n------------------\n");

	return 0;
}
