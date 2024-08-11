#include "deck.h"
#include "discardPile.h"
#include "draw.h"
#include "hand.h"
#include "jokerDeck.h"
#include "playingCard.h"
#include "shop.h"
#include "tools.h"
#include <array>
#include <cmath>
#include <cstdio>
#include <sstream>

const std::string CARD_NOT_FOUND = "Card ID not found";
const std::string NO_DISCARDS = "No discards left";

std::pair<std::array<int, 5>, char> getInput(bool &shouldExit) {
  std::array<int, 5> values = {0, 0, 0, 0, 0};
  std::string input;
  char action = ' ';

  std::cout << "Enter 'p' to play or 'd' to discard followed by 5 integers "
               "separated by spaces, or 'q' to quit: ";
  std::getline(std::cin, input);

  if (input == "q") {
    shouldExit = true;
    return {values, action};
  }

  std::istringstream stream(input);
  stream >> action;

  if (action == 'p' || action == 'd') {
    for (int i = 0; i < 5; ++i) {
      stream >> values[i];
    }
  }
  return {values, action};
}

std::array<PlayingCard, 5> getCards(std::array<int, 5> IDs, Draw &draw) {
  std::array<PlayingCard, 5> playingcards;
  int counter = 0;
  int drawSize = DEFAULT_DRAW_SIZE;

  for (int i = 0; i < drawSize; i++) {
    PlayingCard *card = draw.get(i);

    if (card == nullptr) {
      printError(CARD_NOT_FOUND);
      break;
    }

    for (int j = 0; j < 5; j++) {
      if (card->getID() == IDs[j]) {
        playingcards[counter] = *card;
        counter++;
        break;
      }
    }
  }

  return playingcards;
}

void initializeDeck(Deck &deck) {
  deck.populateBoard();
  deck.shuffle();
  deck.toString();
}

void initializeDraw(Draw &draw, Deck &deck) {
  draw.drawTillFull(deck);
  draw.toString();
  printf("Cards In Deck : %d \n", deck.getDeckSize());
}

void finalizePlay(int mult, int chips, int &totalScore, int level,
                  int stakeHeight, int hands, int discards) {
  printf("Level : %d\n", level);
  printf("Stake : %d\n", stakeHeight);
  printf("Hands Left : %d\n", hands);
  printf("Discards Left : %d\n", discards);
  int currentScore = mult * chips;
  printf("Multiplier: %d \n", mult);
  printf("Chips : %d \n", chips);
  totalScore += currentScore;
  printf("Score : %d \n", currentScore);
  printf("Total Score : %d \n", totalScore);
}
int calculateStake(int &level) {
  const int baseStake = 100;

  const double growthRate = 1.5;

  int stake = static_cast<int>(baseStake * std::pow(growthRate, level - 1));

  return std::max(stake, baseStake);
}

bool playStage(int stakeHeight, int &level, Deck &deck) {

  DiscardPile discardPile(52);
  Draw draw;

  int hands{3};
  int discards{3};
  int totalScore{0};

  bool shouldExit = false;

  while (totalScore < stakeHeight && !shouldExit && hands != 0) {
    initializeDraw(draw, deck);

    std::pair<std::array<int, 5>, char> numbers = getInput(shouldExit);
    if (shouldExit) {
      return false;
    }
    std::array<int, 5> cardIds = numbers.first;
    char action = numbers.second;

    /* The following might be the best code piece of code In this project */
    std::array<PlayingCard, 5> cards = getCards(cardIds, draw);

    switch (action) {
    case 'd':
      if (discards != 0) {
        draw.discardCards(cardIds, discardPile, deck);
        discards -= 1;
      } else {
        printError(NO_DISCARDS);
      }
      continue;
    case 'p':
      draw.discardCards(cardIds, discardPile, deck);
      hands -= 1;
    }
    Hand hand(cards, 0, 0);

    std::pair<HandType, Points> evaluation = hand.evaluate();
    HandType type = evaluation.first;
    Points points = evaluation.second;
    int chips = points.chips;
    int mult = points.multiplier;

    hand.printHandType(type);
    finalizePlay(mult, chips, totalScore, level, stakeHeight, hands, discards);
  }

  if (totalScore >= stakeHeight) {
    printf("Congratulations, you beat level %d!!!\n", level);
    return true;
  }
  if (hands == 0) {
    printf("DEFEAT\nLevel : %d\n", level);
  }
  return false;
}

int main() {
  int something = 1;
  int level = 1;
  bool keepPlaying{true};
  Shop shop{};
  shop.set();
  shop.print();

  Deck deck;
  deck.populateBoard();
  JokerDeck jdeck(5);
  int money = 5;
  while (keepPlaying) {
    int stake = calculateStake(level);
    deck.toString();
    keepPlaying = playStage(stake, level, deck);
    level++;
    shop.buy(money, jdeck, deck);
  }
}
