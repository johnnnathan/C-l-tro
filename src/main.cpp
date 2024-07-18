#include "deck.h"
#include "playingCard.h"


int main (int argc, char *argv[]) {
  Deck deck(52);
  deck.populateBoard();
  deck.shuffle();
  deck.toString();
  return 0;
}
