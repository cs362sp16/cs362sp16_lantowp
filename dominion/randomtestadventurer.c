#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


//This randomly tests Adventurer


int main() {
	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, treasure_map};
	  int i, j, players, handCount, deckCount, seed;
		int player = 0;
		int empty_deck_chance = 3;
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

			printf("card\n");
			fflush(stdout);
			cardEffect(adventurer, 1, 1, 1, &state, 0, 0);		//Run adventurer card
			printf("card\n");
			fflush(stdout);


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
