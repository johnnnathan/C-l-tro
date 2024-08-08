#include "hand.h"
#include "handTypes.h"
#include "points.h"
#include "tools.h"
#include <array>
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
  std::array<int, 5> wanted = {0, 9, 10, 11, 12};
  return areIn(intArray, wanted);
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

void Hand::findPairs() {
  std::pair<int, int> pairCount = {0, 0};
  int cardCount =
      cards.size(); // might be able to use sizeof(cards)/sizeof(PlayingCard)
  std::vector<bool> pos;
  int ranks[13] = {0};

  // populate the ranks array with the count of appearance of each rank
  for (int i = 0; i < cardCount; i++) {
    ranks[static_cast<int>(cards[i].getRank())] += 1;
  }

  // loop over all of the ranks and find the two most common ranks
  for (int i = 0; i < 13; i++) {
    if (ranks[i] > pairCount.first) {
      pairCount.second = pairCount.first;
      pairCount.first = ranks[i];
    } else if (ranks[i] > pairCount.second) {
      pairCount.second = ranks[i];
    }
  }

  // loop over the cards in the hand and set its position to be true in the
  // array
  for (int i = 0; i < cardCount; i++) {
    bool flag = false;
    if ((pairCount.first > 1 &&
         ranks[static_cast<int>(cards[i].getRank())] == pairCount.first) ||
        pairCount.second > 1 &&
            ranks[static_cast<int>(cards[i].getRank())] == pairCount.second) {
      flag = true;
    }
    pos.push_back(flag);
    std::cout << pos[i] << ' ' << static_cast<int>(cards[i].getRank()) << '\n';
  }

  this->pairTypes = pairCount;
  this->positions = pos;
}

std::pair<HandType, Points> Hand::evaluate() {
  if (cards.size() != 5 || isIn(toIntArray(), 0)) {
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

  scoreCards();
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

void Hand::scoreCards() {
  int rankValue;
  for (int i = 0; i < 5; i++) {
    if (positions[i]) {
      rankValue = static_cast<int>(cards[i].getRank());
    }
    if (rankValue > 11) {
      rankValue = 10;
    }
    points.chips += rankValue;
  }
}
