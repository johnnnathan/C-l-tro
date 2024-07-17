#include "deck.h"
#include "playingCard.h"
#include <cstdlib>
#include <utility>

Deck::Deck(int size) {
    deck = new PlayingCard*[size];
    deckSize = size;
}
Deck::~Deck(){
  for (int card = 0; card < deckSize; card++){
    delete deck[card];
  }
  delete deck;
}

void Deck::toString(){
  int size = this->getDeckSize();
  for (int i = 0; i < size; i++){
    std::cout << *(deck[i]) << std::endl;
  }
}
void Deck::populateBoard(){
  int counter = 0;
  for (int rank = 1; rank < 14; rank++){
    for (int suit = 1; suit < 5; suit++){
      PlayingCard *card = new PlayingCard(rank,suit, NO_ENHANCEMENT, NO_EDITION, NO_SEAL);
      deck[counter] = card; 
      counter += 1;
    }
  }
}

void Deck::addCard(PlayingCard* card){
  int deckSize = getDeckSize();
  PlayingCard* newDeck [deckSize + 1];
  for (int card = 0; card < deckSize; card++){
    newDeck[card] = deck[card];
  }
  newDeck[deckSize] = card;
  delete[] deck;
  deck = newDeck; 
  alterDeckSize(1);
}

void Deck::removeCard(int cardID){
  PlayingCard* newDeck [deckSize - 1];
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
  alterDeckSize(-1);
}


int Deck::getDeckSize(){
  return deckSize;
}

void Deck::shuffle(){
  int index;
  std::srand(std::time(NULL));
  for (int i = getDeckSize(); i >= 0; i--){
    index = std::rand() % (i);
    std::swap(deck[i], deck[index]);
  }
}


void Deck::alterDeckSize(int change){
  deckSize += change;
}

PlayingCard* Deck::operator[](int index) const {
    if (index < 0 || index >= deckSize) {
        throw std::out_of_range("Index out of range");
    }
    return deck[index];
}


