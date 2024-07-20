#include "hand.h"
#include "points.h"
#include <array>
#include <utility>


Hand::Hand(const std::array<PlayingCard, 5>& cards, int multiplier, int chips)
    : cards(cards), points{multiplier, chips} {
}


std::vector<bool> Hand::getPositions() const{
  return this->positions;
}
std::pair<int,int> Hand::getPairTypes() const{
  return this->pairTypes;
}

bool Hand::isHighCard() const{
  if(getPairTypes().first == 1){
    return true;
  }
  return false;

}
bool Hand::isPair() const{
  std::pair<int,int> pair = getPairTypes();
  if(pair.first == 2 && pair.second == 1){
    return true;
  }
  return false;

}
bool Hand::isTwoPair() const{
  std::pair<int,int> pair = getPairTypes();
  if (pair.first == pair.second && pair.first == 2){
    return true;
  }
  return false;

}
bool Hand::isThreeOfAKind() const{
  std::pair<int,int> pair = getPairTypes();
  if(pair.first == 3 && pair.second ==1){
    return true;
  }
  return false;


}
bool Hand::isFourOfAKind() const{
  std::pair<int,int> pair = getPairTypes();
  if(pair.first == 4){
    return true;
  }
  return false;

}
bool Hand::isFiveOfAKind() const{
  std::pair<int,int> pair = getPairTypes();
  if(pair.first == 5){
    return true;
  }
  return false;

}
bool Hand::isFullHouse() const{
  std::pair<int,int> pair = getPairTypes();
  if (pair.first == 3 && pair.second == 2){
    return true;
  }
  return false;

}
bool Hand::isFlush() const{
  bool flush = true;
  for(int i = 1; i < cards.size(); i++){
    if(cards[i].getSuit() != cards[i - 1].getSuit()){
      flush = false; 
    }
  }
  return flush;
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
    


void Hand::findPairs(){
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

  this->pairTypes = pairCount;
  this->positions = positions;
}


std::pair<HandType, Points> Hand::evaluate(){
  findPairs();

}
