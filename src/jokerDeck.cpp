#include "jokerDeck.h"
#include "joker.h" 
#include "tools.h"

const std::string FULL_JOKER_DECK = "You can not add any more jokers, at capacity";
const std::string EMPTY_JOKER_DECK = "No Jokers, cannot remove";
const std::string JOKER_NOT_FOUND = "Joker not found, cannot remove";
void JokerDeck::addJoker(Joker* joker){
  if (!(getJokerCount() < getDeckSize())){
    printError(FULL_JOKER_DECK);
    return;
  }
  jokers[getJokerCount()] = joker;
  incrementCurrent();

}

void JokerDeck::removeJoker(std::string jokerName){
  if (getJokerCount() == 0){
    printError(EMPTY_JOKER_DECK);
    return;
  }
  for (int i = 0; i < getJokerCount(); i++){
    if (jokers[i]->getName() == jokerName){
      delete jokers[i];
      return;
    }

  }
  printError(JOKER_NOT_FOUND);
  decrementCurrent();
}

void JokerDeck::decrementCurrent(){
  currentJokers -= 1;
}

void JokerDeck::incrementCurrent(){
  currentJokers += 1;
}
