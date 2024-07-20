#include "hand.h"
#include "points.h"
#include <array>
#include <utility>


Hand::Hand(const std::array<PlayingCard, 5>& cards, int multiplier, int chips)
    : cards(cards), points{multiplier, chips} {
}

bool Hand::isHighCard() const{

}
bool Hand::isPair() const{

}
bool Hand::isTwoPair() const{

}
bool Hand::isThreeOfAKind() const{

}
bool Hand::isFourOfAKind() const{

}
bool Hand::isFiveOfAKind() const{

}
bool Hand::isFullHouse() const{

}
bool Hand::isFlush() const{

}
bool Hand::isStraight() const{

}
bool Hand::isStraightFlush() const{

}
bool Hand::isRoyalFlush() const{

}
bool Hand::isFlushHouse() const{

}
bool Hand::isFlushFive() const{

}
    


std::pair<std::pair<int,int>,std::vector<bool>> Hand::findPairs(){
  std::pair<int,int> pairCount = {0,0};
  int cardCount = cards.size(); //might be able to use sizeof(cards)/sizeof(PlayingCard)
  std::vector<bool> positions(cardCount, false);
  int ranks[13] = {0};

  for (int i = 0; i < cardCount; i++){
    ranks[cards[i].getRank()] += 1;
  }

  for (int i = 0; i < 13; i++){
    if (ranks[i] > pairCount.first){
      pairCount.second = pairCount.first;
      pairCount.first = ranks[i];
    }
    else if (ranks[i] > pairCount.second) {
      pairCount.second = ranks[i];
    }
  }

  for (int i = 0; i < cardCount; i++){
    if(ranks[cards[i].getRank()] == pairCount.first || ranks[cards[i].getRank()] == pairCount.second){
      positions[i] = true;
    }
  }

  std::pair<std::pair<int, int>, std::vector<bool>> total = {pairCount,positions};
  return total;
}
