#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

int main (int argc, char** argv) {
  int num_of_compares = 1000000;
  int random_num_range = 1000;

  srand(time(NULL));

  //Compare for less than
  for (int i = 0; i < num_of_compares; i++) {
    int a = rand()%random_num_range;
    int b = a + rand()%random_num_range;
    assert(compare(a,b) == -1 && "Failed less than tests.");
  }

  //Compare for greater than
  for (int i = 0; i < num_of_compares; i++) {
    int a = rand()%random_num_range;
    int b = a - rand()%random_num_range;
    assert(compare(a,b) == 1 && "Failed greater than tests.");
  }

  //Compare for equal values
  for (int i = 0; i < num_of_compares; i++) {
    int a = rand()%random_num_range;
    assert(compare(a,a) == 0 && "Failed equal to tests.");
  }

  return 0;
}
