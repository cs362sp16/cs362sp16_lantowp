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

  //Test intial hand size
  assert(numHandCards(game_state) == 5 && "Initial hand size isn't 5\n");

  //Test if a card is drawn
  drawCard(game_state->whoseTurn, game_state);
  assert(numHandCards(game_state) == 6 && "Drawn hand size isn't 6\n");

  return 0;
}
