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

  printf ("Starting game.\n");

  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state);

  //Test intial hand size
  if (my_assert(numHandCards(&game_state) == 5, "Initial hand size isn't 5\n")) {
    return 0;
  }

  //Test if a card is drawn
  drawCard(game_state.whoseTurn, &game_state);
  if (my_assert(numHandCards(&game_state) == 6, "Drawn hand size isn't 6\n")) {
    return 0;
  }

  printf ("All tests passed for numHandCards()\n");

  return 0;
}
