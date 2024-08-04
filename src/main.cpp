#include "deck.h"
#include "discardPile.h" // Assuming this is correctly implemented
#include "draw.h"
#include "hand.h"
#include "playingCard.h"
#include <array>
#include <cstdio>
#include <sstream>

std::array<int, 5> getInput(bool &shouldExit) {
  std::array<int, 5> values;
  std::string input;

  std::cout << "Enter 5 integers separated by spaces or 'q' to quit: ";
  std::getline(std::cin, input);

  if (input == "q") {
    shouldExit = true;
    return values;
  }

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
  Deck deck;

  deck.populateBoard();
  deck.shuffle();
  deck.toString();

  DiscardPile discardPile(52);

  Draw draw;
  bool shouldExit = false;
  int totalScore{0};
  while (totalScore < 250 && !shouldExit) {
    draw.drawTillFull(deck);
    draw.toString();
    printf("Cards In Deck : %d \n", deck.getDeckSize());
    std::array<int, 5> numbers = getInput(shouldExit);
    if (shouldExit) {
      break;
    }
    std::array<PlayingCard, 5> cards = getCards(numbers, draw);
    draw.discardCards(numbers, discardPile, deck);
    Hand hand(cards, 0, 0);
    std::pair<HandType, Points> evaluation = hand.evaluate();
    hand.printHandType(evaluation.first);
    int currentScore = evaluation.second.chips * evaluation.second.multiplier;
    printf("Multiplier: %d \n", evaluation.second.multiplier);
    printf("Chips : %d \n", evaluation.second.chips);
    totalScore += currentScore;
    printf("Score : %d \n", currentScore);
    printf("Total Score : %d \n", totalScore);
  }
}
