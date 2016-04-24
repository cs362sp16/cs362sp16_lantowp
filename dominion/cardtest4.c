#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  struct gameState game_state;
  int num_of_players = 2;
  int cards[10] = {council_room, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
  int initial_num_cards;
  int initial_num_buy;

  printf ("Starting game.\n");

  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state);

  //Test for correct return value
  initial_num_cards = numHandCards(&game_state);
  initial_num_buy = game_state.numBuys;
  assert(cardEffect(village, 0, 0, 0, &game_state, 0, 0) == 0
        && "Incorrect return value for Council Room\n");

  //Test for 4 cards drawn
  assert(numHandCards(&game_state) == initial_num_cards + 3
        && "Council Room drew wrong number of cards\n");

  //Test for +1 buy
  assert(game_state.numBuys == initial_num_buy + 1
        && "Council Room added an incorrect number of buys\n");

  //Test for opponent's card drawn
  endTurn(&game_state);
  assert(numHandCards(&game_state) == initial_num_cards + 1
        && "Council Room drew wrong number of cards for opponent\n");

  printf ("All tests passed for Council Room\n");

  return 0;
}
