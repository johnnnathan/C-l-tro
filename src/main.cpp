#include "deck.h"
#include "playingCard.h"
#include <iostream>



int main (int argc, char *argv[]) {
  Deck deck(52);  
  deck.populateBoard();
  for (int i = 0; i < 52; i++){
    std::cout << deck[i];
  }
  return 0;
}
