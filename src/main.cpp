#include "deck.h"
#include "discardPile.h" // Assuming this is correctly implemented
#include "draw.h"
#include "hand.h"
#include "playingCard.h"
#include <array>
#include <sstream>

std::array<int, 5> getInput() {
  std::array<int, 5> values;
  std::string input;

  std::cout << "Enter 5 integers separated by spaces: ";
  std::getline(std::cin, input);

  std::istringstream stream(input);
  for (int i = 0; i < 5; ++i) {
    stream >> values[i];
  }

  return values;
}

std::array<PlayingCard, 5> getCards(std::array<int, 5> IDs, Deck &deck) {

  std::array<PlayingCard, 5> playingcards;
  int counter = 0;
  for (int i = 0; i < deck.getDeckSize(); i++) {
    for (int j = 0; j < 5; j++) {
      if (deck[i] != nullptr && deck[i]->getID() == IDs[j]) {
        playingcards[counter] = *deck[i];
        counter++;
      }
    }
  }
  return playingcards;
}
int main() {
  // Create a deck with a fixed size (for simplicity, using 5 cards)
  Deck deck;

  deck.populateBoard();
  deck.shuffle();
  deck.toString();

  DiscardPile discardPile(52);
  Draw draw;
  draw.drawTillFull(deck);
  draw.toString();
  std::array<int, 5> numbers = getInput();
  std::array<PlayingCard, 5> cards = getCards(numbers, deck);
  std::cout << cards[0].toString() << '\n';
  std::cout << cards[1].toString() << '\n';
  std::cout << cards[2].toString() << '\n';
  std::cout << cards[3].toString() << '\n';
  std::cout << cards[4].toString() << '\n';
  Hand hand(cards, 0, 0);
  std::pair<HandType, Points> evaluation = hand.evaluate();
  hand.printHandType(evaluation.first);
  std::cout << evaluation.second.chips << '\n';
  // something
}
