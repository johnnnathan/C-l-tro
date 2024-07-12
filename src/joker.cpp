#include <cstdint>
#include <iostream>
#include "joker.h"
#include "tools.h"


Joker::Joker(int activation_code, int rarity, int edition){
  data = 0;
  setRarity(rarity);
  setActivateOn(activation_code);
  setEdition(edition);
}
void Joker::setEdition(int edition){
  if (!checkRange(1, 5, edition)){
    printError(OUT_OF_RANGE_ERROR); 
    return;
  } 
  clearAndSet(data, edition, EDITION_MASK, EDITION_SHIFT);
}

std::string Joker::getDescription(){
  return description;
}
int Joker::getEdition(){
  return (data >> EDITION_SHIFT) & 0b111;
} 

int Joker::getRarity(){
  return (data >> RARITY_SHIFT) & 0b11;
}

int Joker::getActivatedOn(){
  return (data & 0b11);
}

void Joker::toString(){
  std::ostringstream oss;
  std::cout << "Joker [Activation Code: " << getActivatedOn()
        << ", Rarity: " << getRarity()
        << ", Edition: " << getEdition()
        << ", Data: " << static_cast<int>(data)
        << ", Description: " << getDescription() << "]";
}
void Joker::setRarity(int rarity){
  if(!checkRange(1,4,rarity)){
    printError(OUT_OF_RANGE_ERROR); 
    return;
  }
  clearAndSet(data,rarity,RARITY_MASK, RARITY_SHIFT);
}
void Joker::setActivateOn(int activation_code){
  if (!checkRange(1,4,activation_code)){
    printError(OUT_OF_RANGE_ERROR); 
    return;
  }
  clearAndSet(data, activation_code, ACTIVATION_CODE_MASK, ACTIVATION_SHIFT);
}

uint8_t Joker::getData(){
  return data;
}

void Joker::setDescription(std::string text){
  description = text;
}


int main (int argc, char *argv[]) {
  Joker joker(1,1,1);
  joker.setDescription("There was a joker whose name was joker");
  joker.toString();
}
