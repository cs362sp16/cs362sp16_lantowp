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
  int init_hand_size;
  int total_draws = 5;

  printf ("Starting game.\n");

  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state);

  //Test if a card is drawn
  init_hand_size = numHandCards(&game_state);
  for (int num_of_draws = 1; num_of_draws <= total_draws; num_of_draws++) {
    drawCard(game_state.whoseTurn, &game_state);
    if (my_assert(numHandCards(&game_state) == init_hand_size + num_of_draws,
    "Drawn hand size isn't correct\n")) {
      return 0;
    }
  }

  //Test if hand has cards
  for (int i = 0; i < init_hand_size + total_draws; i++) {
    if (my_assert(game_state.hand[game_state.whoseTurn][i] != 0,
    "Invalid cards added\n")) {
      return 0;
    }
  }

  printf ("All tests passed for drawCard()\n");

  return 0;
}
