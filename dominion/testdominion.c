#include "dominion.h"
#include "interface.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* get_card_name(int card){
  switch(card){
  case curse: return ("Curse");
    break;
  case estate: return ("Estate");
    break;
  case duchy: return ("Duchy");
    break;
  case province: return ("Province");
    break;
  case copper: return ("Copper");
    break;
  case silver: return ("Silver");
    break;
  case gold: return ("Gold");
    break;
  case adventurer: return ("Adventurer");
    break;
  case council_room: return ("Council Room");
    break;
  case feast: return ("Feast");
    break;
  case gardens: return ("Gardens");
    break;
  case mine: return ("Mine");
    break;
  case remodel: return ("Remodel");
    break;
  case smithy: return ("Smithy");
    break;
  case village: return ("Village");
    break;
  case baron: return ("Baron");
    break;
  case great_hall: return ("Great Hall");
    break;
  case minion: return ("Minion");
    break;
  case steward: return ("Steward");
    break;
  case tribute: return ("Tribute");
    break;
  case ambassador: return ("Ambassador");
    break;
  case cutpurse: return ("Cutpurse");
    break;
  case embargo: return ("Embargo");
    break;
  case outpost: return ("Outpost");
    break;
  case salvager: return ("Salvager");
    break;
  case sea_hag: return ("Sea Hag");
    break;
  case treasure_map: return ("Treasure Map");
    break;

  default: return ("?");
  }

}

int main (int argc, char** argv) {
  srand(time(NULL));

  struct gameState G;
  struct gameState *state = &G;

  char *card_name = NULL;

  int i, j, random_number, card_bought, random_card, card_played, choice1, choice2, choice3;
  // int money = 0;
  int num_players = 2 + rand()%3;
  int num_cards = 25;
  int deck_size = 10;
  int num_possible = 13;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine,
        cutpurse, feast, tribute, smithy};
  // int kingdomCards[deck_size];
  // int possible_cards[13] = {adventurer, gardens, embargo, village, minion, mine,
  //       cutpurse, sea_hag, tribute, smithy, council_room, feast, remodel};
  // int random_array[deck_size];
  //
  //
  // //Seed the deck
  // for(i = 0; i < deck_size; i++) {
  //   random_array[i] = rand()%num_possible;
  //   for(j = 0; j < deck_size; j++) {
  //     if(random_array[i] == random_array[j]) {
  //       i--;
  //       break;
  //     }
  //   }
  // }
  //
  //
  // for (i = 0; i < deck_size; i++) {
  //   kingdomCards[i] = random_array[i];
  // }

  printf("Starting game with %d players.\n", num_players);

  //Initialize Game
  if(initializeGame(num_players, kingdomCards, atoi(argv[1]), state) == -1) {
    printf("Error creating game\n");
  }

  //Plays each turn until game finishes.
  while (!isGameOver(state)) {
    //Current state
    printState(state);

    //Play a card
    for (i = 0; i < numHandCards(state); i++) {
      card_played = handCard(i, state);
      choice1 = rand()%2+1;
      choice2 = rand()%2+1;
      choice3 = rand()%2+1;

      if(playCard(i, choice1, choice2, choice3, state) != -1) {
        printf("Player %d played %s.\n", state->whoseTurn, get_card_name(card_played));
        printf("Choice 1: %d, Choice 2: %d, Choice 3: %d\n\n",choice1, choice2, choice3);
      }
    }

    //Buying phase
    printf("Buying phase\n");
    card_bought = 0;
    i = 0;
    while(!card_bought && i < num_cards) {
      random_card = kingdomCards[rand()%deck_size];
      if (i == 0 && rand()%(deck_size-1) == 0) {
        random_card = gold;
      }
      if (i == 1 && rand()%(deck_size-1) == 0) {
        random_card = silver;
      }
      if (i == 2 && rand()%(deck_size-1) == 0) {
        random_card = copper;
      }
      if(buyCard(random_card, state) != -1) {
        card_bought = 1;
        printf("Player %d bought %s for %d coins.\n", state->whoseTurn,
              get_card_name(random_card), getCost(random_card));
      }
      i++;
    }

    printf("\nEnding Player %d's turn.\n\n",state->whoseTurn);
    //end turn
    endTurn(state);
  }

  //End Game
  printf("\n\n");
  printScores(state);

  return 0;
}
