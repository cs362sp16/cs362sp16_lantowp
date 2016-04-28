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
  int initial_num_cards;

  printf ("Starting game.\n");

  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state);

  //Test for correct return value
  initial_num_cards = numHandCards(&game_state);
  my_assert(cardEffect(smithy, 0, 0, 0, &game_state, 0, 0) == 0,
        "Incorrect return value for Smithy\n");

  //Test for 3 cards drawn
  my_assert(numHandCards(&game_state) == initial_num_cards + 2,
        "Smithy drew wrong number of cards\n");

  printf ("All tests passed for Smithy\n");

  return 0;
}
