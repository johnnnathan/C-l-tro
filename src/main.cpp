#include "deck.h"
#include "discardPile.h" // Assuming this is correctly implemented
#include "draw.h"
#include "hand.h"
#include "playingCard.h"
#include <array>
#include <cstdio>
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

std::array<PlayingCard, 5> getCards(std::array<int, 5> IDs, Draw &draw) {
  std::array<PlayingCard, 5> playingcards;
  int counter = 0;
  int drawSize = DEFAULT_DRAW_SIZE;

  for (int i = 0; i < drawSize; i++) {
    PlayingCard *card = draw.get(i);

    if (card != nullptr) {
      for (int j = 0; j < 5; j++) {
        if (card->getID() == IDs[j]) {
          playingcards[counter] = *card;
          counter++;
          break;
        }
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
  deck[0]->toString();
  deck.toString();

  DiscardPile discardPile(52);
  Draw draw;
  draw.drawTillFull(deck);
  draw.toString();
  std::array<int, 5> numbers = getInput();
  std::array<PlayingCard, 5> cards = getCards(numbers, draw);
  Hand hand(cards, 0, 0);
  std::pair<HandType, Points> evaluation = hand.evaluate();
  hand.printHandType(evaluation.first);
  printf("Multiplier: %d \n", evaluation.second.multiplier);
  printf("Chips : %d \n", evaluation.second.chips);
  printf("Total : %d \n",
         evaluation.second.chips * evaluation.second.multiplier);
  // something
}
