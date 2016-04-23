#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  struct gameState game_state;
  int num_of_players = 2;
  int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");

  initializeGame(num_of_players, cards, atoi(argv[1]),
        &numHandCards(struct gameState *game_state));

  //Initial Test
  assert(isGameOver(game_state) == 0 && "Initial game registered as game over.");

  //Test for empty province stack
  game_state->supplyCount[province] = 0;
  assert(isGameOver(game_state) == 1 && "Game continues despite empty province stack.");
  game_state->supplyCount[province] = 1;

  //Test for 3 supply decks empty ending
  state->supplyCount[0] = 0;
  state->supplyCount[1] = 0;
  state->supplyCount[2] = 0;
  assert(isGameOver(game_state) == 1 && "Game continues despite 3 empty supply decks.");

  return 0;
}
