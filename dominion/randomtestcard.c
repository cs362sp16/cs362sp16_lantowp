#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


//This randomly tests Village

int my_assert(int passed, char *message) {
  //Test failed
  if (passed == 0) {
    printf("TEST FAILED:\n%s", message);
    return 1;
  }

  //Test passed
  return 0;
}

int main() {
	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, treasure_map};
	  int i, j, players, handCount, deckCount, seed;
		int initial_num_actions;
		int player = 0;
		int num_tests = 200;

	  struct gameState state;

		// srand(time(NULL));

	  printf("Running Random Adventurer Test\n");

	  for (i = 0; i < num_tests; i++) {
			printf("%d\n",i);
			players = rand() % MAX_PLAYERS;

			seed = rand();		//pick random seed

			initializeGame(players, k, seed, &state);	//initialize Gamestate

			//Initiate valid state variables
			state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			state.discardCount[player] = rand() % MAX_DECK;
			state.handCount[player] = rand() % MAX_HAND;


			//Copy state variables
			handCount = state.handCount[player];
			deckCount = state.deckCount[player];
			initial_num_actions = state.numActions;

			//Test for correct return value
		  if (my_assert(cardEffect(village, 0, 0, 0, &state, 0, 0) == 0,
		  "Incorrect return value for Village\n")) {
		    return 0;
		  }

		  //Test for 1 card drawn
		  if (my_assert(numHandCards(&state) == handCount, "Village drew wrong number of cards\n")) {
		    return 0;
		  }

		  //Test for +2 actions
		  if (my_assert(state.numActions == initial_num_actions + 1,
		  "Village added an incorrect number of actions\n")) {
		    return 0;
		  }

			//Clean State
			for (j = 0; j < MAX_PLAYERS; j++) {
				state.deckCount[j] = 0;
				state.discardCount[j] = 0;
			  state.handCount[j] = 0;
			}
	  }

	  printf("Tests Complete\n");

	  return 0;
}
