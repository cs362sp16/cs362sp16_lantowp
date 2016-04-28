#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int my_assert(int passed, char *message) {
  //Test failed
  if (passed == 0) {
    printf("TEST FAILED:\n%s", message);
    return 1;
  }

  //Test passed
  return 0;
}

int main (int argc, char** argv) {
  struct gameState game_state;
  int num_of_players = 2;
  int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
  int initial_num_cards;
  int initial_num_actions;

  printf ("Starting game.\n");

  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state);

  //Test for correct return value
  initial_num_cards = numHandCards(&game_state);
  initial_num_actions = game_state.numActions;
  if (my_assert(cardEffect(village, 0, 0, 0, &game_state, 0, 0) == 0,
  "Incorrect return value for Village\n")) {
    return 0;
  }

  //Test for 1 card drawn
  if (my_assert(numHandCards(&game_state) == initial_num_cards,
  "Village drew wrong number of cards\n")) {
    return 0;
  }

  //Test for +2 actions
  if (my_assert(game_state.numActions == initial_num_actions + 1,
  "Village added an incorrect number of actions\n")) {
    return 0;
  }

  printf ("All tests passed for Village\n");

  return 0;
}
