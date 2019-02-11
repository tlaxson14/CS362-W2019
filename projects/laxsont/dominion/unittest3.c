/****************************************
* NAME: Travis Laxson
* DATE: 10 Feb 2019
* DESCRIPTION: Functional unit testing file
  for testing the buyCard function
  found in the dominion.c source code.
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/* Boolean values */
typedef enum {false = 0, true = 1} bool;

int main()
{
  int supplyPos = 2;
  struct gameState state1;
  struct gameState state2;
  struct gameState state3;
  bool passed1;
  bool passed2;
  bool passed3;

  /* Initialize state member vars */
  state1.numBuys = 4;
  state1.coins = 12;
  state2.numBuys = 2;
  state2.coins = 10;
  state3.numBuys = 0;
  state3.coins = 15;

  printf("\n-----------------\n-  UNIT TEST 2  -\n-- buyCard() --\n-----------------\n");

  /* Test for numerb of coins if not enough of */
  printf("\n** buyCar Function Test 1 **\n\t+Tests number of coins\n");
 	if(buyCard(supplyPos, &state1) == -1){
    printf("Test Result: Pass\nState1 coins count: %d\n", state1.coins);
    passed1 = true;
  }
	else {
    printf("Test Result: Fail\nState1 coins count: %d\n", state1.coins);
    passed1 = false;
  }

  /* Test for enough coins */
  printf("\n** buyCar Function Test 2 **\n\t+Ensures enough coins\n");
	if(buyCard(supplyPos, &state2) == 0) {
    printf("Test Result: Pass\nState2 coins count: %d\n", state2.coins);
    passed2 = true;
  }
	else {
    printf("Test Result: Fail\nState1 coins count: %d\n", state2.coins);
    passed2 = false;
  }

  /* Test for no buy actions when hard coded with zero even with enough treasures */
 	printf("\n** buyCard Function Test 3 **\n\t+Ensures enough coins\n\t+No buy actions\n");
	if(buyCard(supplyPos, &state3) == -1) {
    printf("Test Result: Pass\nState3 coins count: %d\n", state3.coins);
    passed3 = true;
  }
	else {
    printf("Test Result: Fail\nState3 coins count: %d\n", state3.coins);
    passed3 = false;
  }

  /* Output status of test */
  if(passed1 && passed2 && passed3)
    printf("\n------------------\n UNIT TEST PASSED \n------------------\n");
  else
    printf("\n------------------\n UNIT TEST FAILED \n------------------\n");

  return 0;
}
