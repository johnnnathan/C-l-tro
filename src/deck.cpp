#include "deck.h"
#include "cardProperties.h"
#include "playingCard.h"
#include <cstddef>
#include <cstdlib>
#include <utility>

std::string POPULATION_ERROR = "Can not populate the board, size less than 52";
std::string NOT_IN_DECK = "Card ID not found inside deck, no changes made";

/* Deck Constructor */
Deck::Deck() {
  resetGlobalID();
  int size = 0;
  deck.reserve(size);
  deckSize = size;
  std::cout << "Deck created with size: " << size << std::endl;
}

/* Loops over every card inside the deck, printing each individual one */
void Deck::toString() {
  for (int i = 0; i < getDeckSize(); i++) {
    if (deck[i] != nullptr) {
      std::cout << deck[i]->toString() << std::endl;
    } else {
      std::cout << "Null card at index " << i << std::endl;
    }
  }
}

/* Simple populator method, returns prematurely if the size of the deck is less
  than 52, Could increase the deck size dynamically but I do not care, since
  this will only be used immediately after deck Initialization*/

void Deck::populateBoard() {
  const Rank ranks[] = {Rank::TWO, Rank::THREE, Rank::FOUR,  Rank::FIVE,
                        Rank::SIX, Rank::SEVEN, Rank::EIGHT, Rank::NINE,
                        Rank::TEN, Rank::JACK,  Rank::QUEEN, Rank::KING,
                        Rank::ACE};
  const Suit suits[] = {Suit::HEARTS, Suit::DIAMONDS, Suit::CLUBS,
                        Suit::SPADES};

  for (Rank rank : ranks) {
    for (Suit suit : suits) {
      PlayingCard *card =
          new PlayingCard(rank, suit, Enhancement::NO_ENHANCEMENT,
                          Edition::NO_EDITION_CARD, Seal::NO_SEAL);
      deck.push_back(card);
      alterDeckSize(1);
    }
  }
}

/*
Parameter: PlayingCard pointer

Return type: void

Description:
  Get the size of the current deck and create a new one with size one greater
than the previous one Add all of the elements of the original array to the new
array Add the card to the last position of the new array Delete the original
array Replace the deck with the new one Increnent the deck size variable by one
*/
void Deck::addCard(PlayingCard *card) {
  deck.push_back(card);
  alterDeckSize(1);
}

/*

Parameter: int that represents the ID of the card that needs to be removed from
the deck

Return type: void

Description:
  Create a new deck with size one less than the length of the current deck
  Loop over all the cards inside the original deck and find the one whose ID
matches the one we are looking for Turn the card into a nullptr and end the Loop
  If the cardID was not found inside the deck we end the process, not replacing
the deck Loop over all the cards again and add any that are not nullptr to the
new deck Replace the deck with the new one Decrement the deck size variable by
one
*/
void Deck::removeCard(int cardID) {
  bool cardInDeck = false;

  for (int i = 0; i < deckSize; i++) {
    if (deck[i] != nullptr && deck[i]->getID() == cardID) {
      deck.erase(deck.begin() + i);
      cardInDeck = true;
      break;
    }
  }
  if (!cardInDeck) {
    std::cout << NOT_IN_DECK << std::endl;
    return;
  }
  alterDeckSize(-1);
}
/* returns the size of the current deck */
int Deck::getDeckSize() { return deckSize; }

/*
This method uses the Fisher-Yates algorithm to shuffle all the cards in the deck
*/
void Deck::shuffle() {
  int index;
  std::srand(std::time(NULL));
  for (int i = getDeckSize() - 1; i > 0; i--) {
    index = std::rand() % (i + 1);
    std::swap(deck[i], deck[index]);
  }
}

/* Simple method that change the deckSize variable by the change Parameter */
void Deck::alterDeckSize(int change) { deckSize += change; }

/* method to override the [] operator to be able to access the cards inside the
 * deck directly */
PlayingCard *Deck::operator[](int index) const {
  if (index < 0 || index >= deckSize) {
    throw std::out_of_range("Index out of range");
  }
  return deck[index];
}

PlayingCard *Deck::getCard() {
  if (deckSize == 0) {
    PlayingCard *NULL_CARD(0);
    return NULL_CARD;
  }
  PlayingCard *card = deck[0];
  removeCard(card->getID());
  return card;
}
