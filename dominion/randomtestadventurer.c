#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


//This randomly tests Adventurer

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
		int k[10];
	  int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, treasure_map};
	  int i, j, players, handCount, deckCount, seed, treasure_count;
		int treasure_total = 2;
		int init_treasure_total;
		int deck_size = 10;
		int player = 0;
		int num_tests = 200;

	  struct gameState state;

		srand(treasure_total);

		//Random deck
		for (j = 0; j < deck_size; j++) {
			k[j] = cards[rand()%deck_size];
		}

	  printf("Running Random Adventurer Test\n");

	  for (i = 0; i < num_tests; i++) {
			players = rand() % MAX_PLAYERS;

			seed = rand();		//pick random seed

			initializeGame(players, k, seed, &state);	//initialize Gamestate

			//Initiate valid state variables
			state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			state.discardCount[player] = rand() % MAX_DECK;
			state.handCount[player] = rand() % MAX_HAND;
			state.numActions = rand();

			//Copy state variables
			handCount = state.handCount[player];
			deckCount = state.deckCount[player];

			//Count amount of treasure
			init_treasure_total = 0;
			for (j = 0; j < handCount; j++) {
				if (state.hand[0][j] == copper || state.hand[0][j] == silver ||
				state.hand[0][j] == gold) {
					init_treasure_total++;
				}
			}

			cardEffect(adventurer, 1, 1, 1, &state, 0, 0);		//Run adventurer card

			//Test card was played and two cards were added
		  if (my_assert(numHandCards(&state) == handCount + 1, "Incorrect hand size from card\n")) {
		    return 0;
		  }

			//Check for two treasures
			treasure_count = 0;
			for (j = 0; j < handCount + 1; j++) {
				if (state.hand[0][j] == copper || state.hand[0][j] == silver ||
				state.hand[0][j] == gold) {
					treasure_count++;
				}
			}
			if (my_assert(treasure_count == init_treasure_total - treasure_total,
			"Incorrect amount of treasure\n")) {
				return 0;
			}

			//Check that the treasures were removed from the deck
			if (my_assert(state.deckCount[player] <= deckCount - treasure_total,
			"Treasure wasn't removed from the deck\n")) {
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
