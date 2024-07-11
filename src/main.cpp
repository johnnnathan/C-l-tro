#include "deck.h"



int main (int argc, char *argv[]) {
  Deck deck(52);  
  deck.populateBoard();
  deck.toString();

  return 0;
}
