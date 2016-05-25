#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv) {
  srand(time(NULL));

  struct gameState Game;
  struct gameState *state = &Game;

  int i, j, random_number, used;
  int money = 0;
  int numSmithies = 0;
  int kingdomCards[10];
  int num_players = 2 + rand()%3;
  int possible_cards[13] = {adventurer, gardens, embargo, village, minion, mine,
       cutpurse, sea_hag, tribute, smithy, council_room, feast, remodel};

  //Seed the deck
  for (j = 0; j < sizeof(kingdomCards)/sizeof(int); j++) {
    random_number = rand()%(sizeof(possible_cards)/sizeof(int));
    kingdomCards[j] = possible_cards[random_number];
  }

  cout << "Starting game with " << num_players << " players." << endl;

  initializeGame(num_players, kingdomCards, atoi(argv[1]), state);

  while (!isGameOver(state)) {
    for (i = 0; i < numHandCards(state); i++) {
      if (handCard(i, state) == copper)
        money++;
      else if (handCard(i, state) == silver)
        money += 2;
      else if (handCard(i, state) == gold)
        money += 3;
    }
  }
