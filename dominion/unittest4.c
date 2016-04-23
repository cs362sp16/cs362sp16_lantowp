#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  struct gameState game_state;
  int num_of_players = 3;
  int num_of_turns = 15;
  int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");

  initializeGame(num_of_players, cards, atoi(argv[1]),
        &numHandCards(struct gameState *game_state));

  //Plays through turns, checking who is active
  for (int current_turn = 0; current_turn < num_of_turns; current_turn++) {
    assert(whoseTurn(game_state) == current_turn%num_of_players
            && "Wrong player has active turn");
    endTurn(game_state);
  }

  return 0;
}
