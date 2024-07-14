#ifndef JOKERDECK_H
#define JOKERDECK_H

#include "joker.h"

const int DEFAULT_DECK_SIZE {5};

class JokerDeck{
  private:
    void incrementDeckSize();
    int deckSize{DEFAULT_DECK_SIZE};
    Joker **jokers;
    int currentJokers{0};
  public:
    void addJoker(Joker *joker);
    void removeJoker(std::string jokerName);
    void printDeck() const;
    int getDeckSize();
    int getJokerCount();
    void incrementCurrent();
    void decrementCurrent();
};



#endif // !JOKERDECK_H
