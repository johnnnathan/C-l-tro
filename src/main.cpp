#include "deck.h"
#include <iostream>



int main (int argc, char *argv[]) {
  Deck deck(52);  
  deck.populateBoard();
  for (int i = 0; i < 52; i++){
    std::cout << *(deck[i]) << std::endl;
  }

  return 0;
}
