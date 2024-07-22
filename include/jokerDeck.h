#ifndef JOKERDECK_H
#define JOKERDECK_H

#include "joker.h"

const int DEFAULT_DECK_SIZE = 5;

const std::string FULL_JOKER_DECK = "You can not add any more jokers, at capacity";
const std::string EMPTY_JOKER_DECK = "No Jokers, cannot remove";
const std::string JOKER_NOT_FOUND = "Joker not found, cannot remove";
const std::string ERROR_ADDING_JOKER = "Could not add joker, try again";

class JokerDeck{
  private:
    void incrementDeckSize();
    int deckSize = DEFAULT_DECK_SIZE;
    Joker **jokers;
    int currentJokers = 0;
  public:
    void addJoker(Joker *joker);
    void removeJoker(std::string jokerName);
    void printDeck();
    int getDeckSize();
    int getJokerCount();
    void incrementCurrent();
    void decrementCurrent();
    JokerDeck(int size) : deckSize(size), currentJokers(0) {
        jokers = new Joker*[deckSize];
        for (int i = 0; i < deckSize; ++i) {
            jokers[i] = nullptr;
        }
    }

    ~JokerDeck() {
        for (int i = 0; i < deckSize; ++i) {
            if (jokers[i] != nullptr) {
                delete jokers[i];
            }
        }
        delete[] jokers;
    }
};


#endif // !JOKERDECK_H
