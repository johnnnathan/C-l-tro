#include "jokerDeck.h"
#include "joker.h" 
#include "tools.h"
#include <iostream>



void JokerDeck::addJoker(Joker* joker){
  if (getJokerCount() >= getDeckSize()){
    printError(FULL_JOKER_DECK);
    return;
  }
  for (int i = 0; i < getDeckSize(); i++){
    if(jokers[i] == nullptr){
      jokers[i] = joker;
      incrementCurrent();
      return;
    }
  }
  printError(ERROR_ADDING_JOKER);
}

void JokerDeck::removeJoker(std::string jokerName){
  if (getJokerCount() == 0){
    printError(EMPTY_JOKER_DECK);
    return;
  }
  for (int i = 0; i < getDeckSize(); i++){
    if (jokers[i] != nullptr && jokers[i]->getName() == jokerName){
      delete jokers[i];
      jokers[i] = nullptr;
      decrementCurrent();
      return;
    }
  }
  printError(JOKER_NOT_FOUND);
}

void JokerDeck::decrementCurrent(){
  currentJokers -= 1;
}

void JokerDeck::incrementCurrent(){
  currentJokers += 1;
}

int JokerDeck::getDeckSize(){
  return deckSize;
}
int JokerDeck::getJokerCount(){
  return currentJokers;
}

 void JokerDeck::printDeck(){
  for (int i = 0; i < getDeckSize(); i++){
    if (jokers[i] != nullptr){
      jokers[i]->toString();
    }
    else{
      std::cout << "Empty Slot \n";
    }
  }
}

int main(int argc, char* argv[]) {
    JokerDeck deck(5);

    Joker* joker1 = new Joker(ON_HELD, LEGENDARY, 1);
    joker1->setDescription("First Joker");
    joker1->setName("Joker One");

    Joker* joker2 = new Joker(ON_SCORED, RARE, 2);
    joker2->setDescription("Second Joker");
    joker2->setName("Joker Two");

    Joker* joker3 = new Joker(ON_PLAYED, UNCOMMON, 3);
    joker3->setDescription("Third Joker");
    joker3->setName("Joker Three");

    deck.addJoker(joker1);
    deck.addJoker(joker2);
    deck.addJoker(joker3);

    std::cout << "Deck after adding three jokers:" << std::endl;
    deck.printDeck();

    deck.removeJoker("Joker Two");
    std::cout << "Deck after removing 'Joker Two':" << std::endl;
    deck.printDeck();

    deck.removeJoker("Nonexistent Joker");
    std::cout << "Attempt to remove a nonexistent joker:" << std::endl;
    deck.printDeck();

    Joker* joker4 = new Joker(ON_INDEPENDENT, COMMON, 4);
    joker4->setDescription("Fourth Joker");
    joker4->setName("Joker Four");

    deck.addJoker(joker4);
    std::cout << "Deck after adding 'Joker Four':" << std::endl;
    deck.printDeck();

    return 0;
}
