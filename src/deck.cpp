#include "playingCard.h"

class Deck{
private:
  playingCard** deck ;
  int deckSize;
public:
  void addCard(playingCard* card);
  void removeCard(int cardID);
  void populateBoard();
  int getDeckSize();
  void alterDeckSize(int change);
  Deck(int size);
  ~Deck();

};

Deck::Deck(int size){
  deck = new playingCard*[size];
  deckSize = size;
}
Deck::~Deck(){
  for (int card = 0; card < deckSize; card++){
    delete deck[card];
  }
  delete deck;
}
void Deck::populateBoard(){
  int counter = 0;
  for (int rank = 1; rank < 14; rank++){
    for (int suit = 1; suit < 5; suit++){
      playingCard *card = new playingCard(rank,suit, NO_ENHANCEMENT, NO_EDITION, NO_SEAL);
      deck[counter] = card; 
      counter += 1;
    }
  }
}

void Deck::addCard(playingCard* card){
  int deckSize = getDeckSize();
  playingCard* newDeck [deckSize + 1];
  for (int card = 0; card < deckSize; card++){
    newDeck[card] = deck[card];
  }
  newDeck[deckSize] = card;
  delete[] deck;
  deck = newDeck; 
  alterDeckSize(1);
}
void Deck::removeCard(int cardID){
  playingCard* newDeck [deckSize - 1];
  for (int cardCounter = 0; cardCounter < deckSize; cardCounter++){
    if (deck[cardCounter]->getID() == cardID){
      delete deck[cardCounter];
      deck[cardCounter] = nullptr;
      break;
    }
  }
  int newDeckCounter = 0;
  for (int cardCount = 0; cardCount < deckSize; cardCount++){
    if (deck[cardCount] == nullptr){
      continue;
    }
    newDeck[newDeckCounter] = deck[cardCount];
    newDeckCounter += 1;
  }
  deckSize -= 1;
}
int Deck::getDeckSize(){
  return deckSize;
}

void Deck::alterDeckSize(int change){
  deckSize += change;
}
