/****************************************
* NAME: Travis Laxson
* DATE: 07 Feb 2019
* DESCRIPTION: Unit testing file for the
  refactored adventurer action game card
  from the dominion.c source code file.
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dominion.h"
#include "rngs.h"

/* Boolean variable typedef */
typedef enum {false = 0, true = 1} bool;

int main() {
  int i, j, value, coinAmount, copyCoinAmount, currentPlayer, totalCards, copyStateTotalCards;
  int players = 2;
  int seed = 1000;
  int handPos = 0;
  int cardsDrawn = 0;
  int choice1 = 0, choice2 = 0, choice3 = 0;
  int bonus = 0;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
                          remodel, smithy, village, baron, great_hall};
  int x = 1000;
  int addedCards = 0;
  bool passed;
  struct gameState state, copyState;

  /* Initialize game state */
  initializeGame(players, kingdomCards, seed, &state);

  printf("\n-----------------\n-  CARD TEST 2  -\n ADVENTURER CARD \n-----------------\n\n");

  /* Test for return values vs expected value */
  for(i=0; i < x; i++) {
    memcpy(&copyState, &state, sizeof(struct gameState));
    value = cardEffect(adventurer, choice1, choice2, choice3, &copyState, handPos, &bonus);
    if(value != 0) {
      passed = false;
      break;
    }
  }
  printf("Returned value: %d\nExpected value: %d\n", value, 0);
  if(passed)
    printf("Result: PASSED RETURN VALUE TEST\n\n");
  else
    printf("Result: FAILED RETURN VALUE TEST\n\n");

  /* Test and validate hand count in the copied gamestate */
  addedCards = 2;
  currentPlayer = whoseTurn(&state);
  for(i=0; i < x; i++) {
      memcpy(&copyState, &state, sizeof(struct gameState));
      cardEffect(adventurer, choice1, choice2, choice3, &copyState, handPos, &bonus);
      if(copyState.handCount[currentPlayer] != state.handCount[currentPlayer] + addedCards) {
          passed = false;
          break;
      }
  }
  printf("Current hand count: %d\nExpected hand count: %d\n", copyState.handCount[currentPlayer], state.handCount[currentPlayer] + addedCards);
  if(passed)
    printf("Result: PASSED HAND COUNT TEST\n\n");
  else
    printf("Result: FAILED HAND COUNT TEST\n\n");

  /* Test and validate the treasure coin count */
  for(i=0; i < x; i++) {
    memcpy(&copyState, &state, sizeof(struct gameState));
    cardEffect(adventurer, choice1, choice2, choice3, &copyState, handPos, &bonus);
    coinAmount = 0;
    j = 0;
    while(j < numHandCards(&state)) {
      if (handCard(j, &state) == copper)
        coinAmount++;
      else if(handCard(j, &state) == silver)
        coinAmount += 2;
      else if(handCard(j, &state) == gold)
        coinAmount += 3;
      j++;
    }

    /* Repeat for copying the coin amount for comparison */
    copyCoinAmount = 0;
    j = 0;
    while(j < numHandCards(&copyState)) {
      if(handCard(j, &copyState) == copper)
        copyCoinAmount++;
      else if(handCard(j, &copyState) == silver)
        copyCoinAmount += 2;
      else if(handCard(j, &copyState) == gold)
        copyCoinAmount += 3;
      j++;
    }

    /* Compare copied coint amount to the coin amount +2 drawn cards */
    /* If copied is less then the test passes */
    if(copyCoinAmount < coinAmount+2) {
      passed = false;
      break;
    }
  }

  /* Print total vs. expected treasure coin counts */
  printf("Total coin count: %d\nExpected coin count: %d\n", copyCoinAmount, coinAmount+2);
  if(passed)
    printf("Result: PASSED COIN COUNT TEST\n\n");
  else
    printf("Result: FAILED COIN COUNT TEST\n\n");

  /* Test and validate the deck and discard pile count are correctly adjusted/accounted for */
  cardsDrawn = 2;
  currentPlayer = whoseTurn(&state);

  for(i=0; i < x; i++) {
    memcpy(&copyState, &state, sizeof(struct gameState));
    cardEffect(adventurer, choice1, choice2, choice3, &copyState, handPos, &bonus);
    totalCards = state.deckCount[currentPlayer] + state.discardCount[currentPlayer];
    copyStateTotalCards = copyState.deckCount[currentPlayer] + copyState.discardCount[currentPlayer];
    if(copyStateTotalCards != totalCards - cardsDrawn) {
      passed = false;
      break;
    }
  }
  /* Print total vs. expected card count */
  printf("Total card count: %d\nExpected card count: %d\n", copyStateTotalCards, totalCards-cardsDrawn);
  if(passed)
    printf("Result: PASSED CARD COUNT TEST\n\n");
  else
    printf("Result: FAILED CARD COUNT TEST\n\n");


  /* Print whether card test passed or failed based on boolean var value */
  if(passed)
    printf("------------------\n CARD TEST PASSED \n------------------\n");
  else
    printf("------------------\n CARD TEST FAILED \n------------------\n");

    return 0;
}
