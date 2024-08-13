#include "hand.h"
#include "cardProperties.h"
#include "deck.h"
#include "draw.h"
#include "handTypes.h"
#include "joker.h"
#include "jokerDeck.h"
#include "points.h"
#include "tools.h"
#include <array>
#include <sys/_types/_sigaltstack.h>
#include <utility>

std::string WRONG_HAND_SIZE = "Hand size not 5, can not proceed";

Hand::Hand(const std::array<PlayingCard, 5> &cards, int multiplier, int chips)
    : cards(cards), points{multiplier, chips} {}

std::array<int, 5> Hand::toIntArray() const {
  std::array<int, 5> result;
  if (cards.size() != 5) {
    printError(WRONG_HAND_SIZE);
    return result;
  }

  for (int i = 0; i < 5; i++) {
    result[i] = static_cast<int>(cards[i].getRank());
  }
  return result;
}
void Hand::printHandType(HandType type) const {
  switch (type) {
  case HandType::HIGH_CARD:
    std::cout << "HIGH_CARD" << '\n';
    break;
  case HandType::ONE_PAIR:
    std::cout << "ONE_PAIR" << '\n';
    break;
  case HandType::TWO_PAIR:
    std::cout << "TWO_PAIR" << '\n';
    break;
  case HandType::THREE_OF_A_KIND:
    std::cout << "THREE_OF_A_KIND" << '\n';
    break;
  case HandType::STRAIGHT:
    std::cout << "STRAIGHT" << '\n';
    break;
  case HandType::FLUSH:
    std::cout << "FLUSH" << '\n';
    break;
  case HandType::FULL_HOUSE:
    std::cout << "FULL_HOUSE" << '\n';
    break;
  case HandType::FOUR_OF_A_KIND:
    std::cout << "FOUR_OF_A_KIND" << '\n';
    break;
  case HandType::STRAIGHT_FLUSH:
    std::cout << "STRAIGHT_FLUSH" << '\n';
    break;
  case HandType::ROYAL_FLUSH:
    std::cout << "ROYAL_FLUSH" << '\n';
    break;
  case HandType::FIVE_OF_A_KIND:
    std::cout << "FIVE_OF_A_KIND" << '\n';
    break;
  case HandType::FLUSH_HOUSE:
    std::cout << "FLUSH_HOUSE" << '\n';
    break;
  case HandType::FLUSH_FIVE:
    std::cout << "FLUSH_FIVE" << '\n';
    break;
  case HandType::ERROR:
    std::cout << "ERROR" << '\n';
    break;
  default:
    std::cout << "UNKNOWN" << '\n';
    break;
  }
}

std::vector<bool> Hand::getPositions() const { return this->positions; }
std::pair<int, int> Hand::getPairTypes() const { return this->pairTypes; }

bool Hand::isHighCard() const {
  if (getPairTypes().first == 1) {
    return true;
  }
  return false;
}
bool Hand::isPair() const {
  std::pair<int, int> pair = getPairTypes();
  if (pair.first == 2 && pair.second == 1) {
    return true;
  }
  return false;
}
bool Hand::isTwoPair() const {
  std::pair<int, int> pair = getPairTypes();
  if (pair.first == pair.second && pair.first == 2) {
    return true;
  }
  return false;
}
bool Hand::isThreeOfAKind() const {
  std::pair<int, int> pair = getPairTypes();
  if (pair.first == 3 && pair.second == 1) {
    return true;
  }
  return false;
}
bool Hand::isFourOfAKind() const {
  std::pair<int, int> pair = getPairTypes();
  if (pair.first == 4) {
    return true;
  }
  return false;
}
bool Hand::isFiveOfAKind() const {
  std::pair<int, int> pair = getPairTypes();
  if (pair.first == 5) {
    return true;
  }
  return false;
}
bool Hand::isFullHouse() const {
  std::pair<int, int> pair = getPairTypes();
  if (pair.first == 3 && pair.second == 2) {
    return true;
  }
  return false;
}
bool Hand::isFlush() const {
  bool flush = true;
  for (int i = 1; i < cards.size(); i++) {
    if (cards[i].getSuit() != cards[i - 1].getSuit()) {
      flush = false;
    }
  }
  return flush;
}
bool Hand::isStraight() const {

  bool flag = true;

  if (cards.size() != 5) {
    return false;
  }
  std::array<PlayingCard, 5> cardArray = cards;
  cardArray = sortPlayingCards(cardArray);
  for (int i = 0; i < 4; i++) {
    if (static_cast<int>(cardArray[i].getRank()) -
            static_cast<int>(cardArray[i + 1].getRank()) !=
        1) {
      flag = false;
      break;
    }
  }
  return flag || isHighStraight();
}

bool Hand::isStraightFlush() const {
  if (isStraight() && isFlush()) {
    return true;
  }
  return false;
}

bool Hand::isRoyalFlush() const { return isHighStraight() && isFlush(); }

bool Hand::isHighStraight() const {

  std::array<int, 5> intArray = toIntArray();
  std::array<int, 5> wanted = {8, 9, 10, 11, 12};
  return areIn(intArray, wanted);
}

void Hand::findRankOccurences(int (&ranks)[13], int cardCount) {
  // Populate the ranks array with the count of appearance of each rank
  for (int i = 0; i < cardCount; i++) {
    int rankIndex = static_cast<int>(cards[i].getRank());
    if (rankIndex < 0 || rankIndex > 12) {
      printf("Error: Rank index out of bounds: %d\n", rankIndex);
      abort(); // This should never happen
    }
    ranks[rankIndex] += 1;
  }
}

bool Hand::isFlushHouse() const {
  if (isFlush() && isFullHouse()) {
    return true;
  }
  return false;
}

bool Hand::isFlushFive() const {
  if (isFlush() && isFiveOfAKind()) {
    return true;
  }
  return false;
}

void Hand::findCommonPairs(std::pair<int, int> &pairCount, int (&ranks)[13]) {
  // Loop over all of the ranks and find the two most common ranks
  for (int i = 0; i < 13; i++) {
    if (ranks[i] > pairCount.first) {
      pairCount.second = pairCount.first;
      pairCount.first = ranks[i];
    } else if (ranks[i] > pairCount.second) {
      pairCount.second = ranks[i];
    }
  }
}

std::vector<bool> Hand::determinePositions(std::pair<int, int> &pairCount,
                                           int cardCount, int (&ranks)[13]) {
  // Loop over the cards in the hand and set its position to be true in the
  // array
  std::vector<bool> pos(
      cardCount, false); // Initialize positions with `false` for all cards
  int max{0};
  int maxIndex{0};

  if (pairCount.first == 1) { // High card scenario
    for (int i = 0; i < cardCount; i++) {
      int currentRank = static_cast<int>(cards[i].getRank());
      if (max < currentRank) {
        max = currentRank;
        maxIndex = i;
      }
    }
    pos[maxIndex] = true;
  } else {
    // Pair or higher scenarios
    for (int i = 0; i < cardCount; i++) {
      int currentRank = static_cast<int>(cards[i].getRank()) + 2;
      bool flag = false;
      if ((pairCount.first > 1 && ranks[currentRank] == pairCount.first) ||
          (pairCount.second > 1 && ranks[currentRank] == pairCount.second)) {
        flag = true;
      }
      pos[i] = flag;
    }
  }
  return pos;
}

void Hand::findPairs() {
  std::pair<int, int> pairCount = {0, 0};
  int cardCount = cards.size();

  // Debug: Print the size of the hand

  int ranks[13] = {0}; // Array to count ranks from 0 to 12

  findRankOccurences(ranks, cardCount);

  findCommonPairs(pairCount, ranks);

  positions = determinePositions(pairCount, cardCount, ranks);

  this->pairTypes = pairCount;
}

std::pair<HandType, Points> Hand::evaluate(Deck &deck, JokerDeck &jdeck,
                                           Draw &draw, int &money) {
  if (cards.size() != 5 || isIn(toIntArray(), 0)) {
    printf("Not a 5 card hand, High_Card Awarded");
    setPoints(points, 1, 5);
    return std::make_pair(HandType::HIGH_CARD, points);
  }
  HandType type;
  findPairs();

  if (isRoyalFlush()) {
    setTrueVector();
    setPoints(points, 8, 100);
    type = HandType::ROYAL_FLUSH;
  } else if (isStraightFlush()) {
    setTrueVector();
    setPoints(points, 8, 100);
    type = HandType::STRAIGHT_FLUSH;
  } else if (isFlushFive()) {
    setTrueVector();
    setPoints(points, 16, 160);
    type = HandType::FLUSH_FIVE;
  } else if (isFiveOfAKind()) {
    setTrueVector();
    setPoints(points, 12, 120);
    type = HandType::FIVE_OF_A_KIND;
  } else if (isFourOfAKind()) {
    setPoints(points, 7, 60);
    type = HandType::FOUR_OF_A_KIND;
  } else if (isFlushHouse()) {
    setTrueVector();
    setPoints(points, 14, 140);
    type = HandType::FLUSH_HOUSE;
  } else if (isFullHouse()) {
    setTrueVector();
    setPoints(points, 4, 40);
    type = HandType::FULL_HOUSE;
  } else if (isFlush()) {
    setTrueVector();
    setPoints(points, 4, 35);
    type = HandType::FLUSH;
  } else if (isStraight()) {
    setTrueVector();
    setPoints(points, 4, 30);
    type = HandType::STRAIGHT;
  } else if (isThreeOfAKind()) {
    setPoints(points, 3, 30);
    type = HandType::THREE_OF_A_KIND;
  } else if (isTwoPair()) {
    setPoints(points, 2, 20);
    type = HandType::TWO_PAIR;
  } else if (isPair()) {
    setPoints(points, 2, 10);
    type = HandType::ONE_PAIR;
  } else if (isHighCard()) {
    setPoints(points, 1, 5);
    type = HandType::HIGH_CARD;
  } else {
    return std::make_pair(HandType::ERROR, points);
  }

  scoreCards(deck, draw, money, jdeck);
  return std::make_pair(type, points);
}

std::vector<bool> getTrueVector() {
  std::vector<bool> trueVector;
  for (int i = 0; i < 5; i++) {
    trueVector.push_back(true);
  }
  return trueVector;
}

void Hand::setTrueVector() { positions = getTrueVector(); }
void Hand::scoreCard(Deck &deck, JokerDeck &jdeck, Draw &draw, int &money,
                     PlayingCard card, int index, bool repeat) {

  int rankValue;
  Seal seal = card.getSeal();
  Enhancement enh = card.getEnhancement();
  Edition edi = card.getEdition();
  int score = card.getScore();
  int temp = positions[index];
  int chips = 0;
  int mult = 0;

  int pos = positions[index];
  if (pos == 0) {
    return;
  }

  chips += score;

  if (temp == 1) {
    rankValue =
        2 + static_cast<int>(card.getRank()); // very ugly but can not spend
    // the time now to fix it
  }
  if (rankValue == 14) {
    rankValue = 11;
  } else if (rankValue > 10) {
    rankValue = 10;
  }

  switch (edi) {
  case Edition::NO_EDITION_CARD:
    break;
  case Edition::FOIL:
    chips += 50;
    break;
  case Edition::POLYCHROME:
    points.multiplier *= 1.5;
    break;
  case Edition::HOLOGRAPHIC:
    mult += 10;
    break;
  }

  int roll;

  switch (enh) {
  case Enhancement::NO_ENHANCEMENT:
    break;
  case Enhancement::BONUS:
    chips += 30;
    break;
  case Enhancement::MULT:
    mult += 4;
    break;
  case Enhancement::GLASS:
    points.multiplier *= 2;
    roll = std::rand() % 4;
    if (roll == 0) {
      deck.removeCard(card.getID());
    }
    break;
  case Enhancement::LUCKY:
    roll = std::rand() % 15;
    if (roll < 5) {
      mult += 20;
    }
    roll = std::rand() % 15;
    if (roll == 0) {
      money += 20;
    }
    break;
  default:
    break;
  }

  // Need to add the purple and blue seals in some way, would require
  // implementing planets cards/hand levels and tarot cards but not in the plans
  // currently
  scoreJokers(deck, money, jdeck, ON_SCORED);
  switch (seal) {
  case Seal::RED_SEAL:
    if (repeat) {
      scoreCard(deck, jdeck, draw, money, card, index,
                false); // set to false to not trigger red seal twice
      repeat = false;   // unecessary but making sure that nothing funky happens
                        // down the line
    }
    break;
  case Seal::GOLD_SEAL:
    money += 3;
    break;
  default:
    break;
  }

  points.chips += rankValue;
  points.multiplier += mult;
}
void Hand::scoreCards(Deck &deck, Draw &draw, int &money, JokerDeck &jdeck) {
  scoreJokers(deck, money, jdeck, ON_HELD);
  for (int i = 0; i < 5; i++) {
    scoreCard(deck, jdeck, draw, money, cards[i], i, true);
  }
}
void Hand::scoreJokers(Deck &deck, int &money, JokerDeck &jdeck, int ON_TYPE) {
  for (int i = 0; i < jdeck.getDeckSize(); i++) {
    if (jdeck.get(i) != nullptr && jdeck.get(i)->getActivatedOn() == ON_TYPE) {
      jdeck.get(i)->operate(nullptr, money, points, deck);
    }
  }
}
