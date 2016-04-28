#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void my_assert(int passed, char *message) {
  //Test failed
  if (passed == 0) {
    printf("TEST FAILED:\n%s", message);
    exit(1);
  }
}

int main (int argc, char** argv) {
  struct gameState game_state;
  int num_of_players = 2;
  int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");

  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state);

  //Initial Test
  my_assert(isGameOver(&game_state) == 0, "Initial game registered as game over.\n");

  //Test for empty province stack
  game_state.supplyCount[province] = 0;
  my_assert(isGameOver(&game_state) == 1, "Game continues despite empty province stack.\n");
  game_state.supplyCount[province] = 1;

  //Test for 3 supply decks empty ending
  game_state.supplyCount[0] = 0;
  game_state.supplyCount[1] = 0;
  game_state.supplyCount[2] = 0;
  my_assert(isGameOver(&game_state) == 1, "Game continues despite 3 empty supply decks.\n");

  printf ("All tests passed for isGameOver()\n");

  return 0;
}
