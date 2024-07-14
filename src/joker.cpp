#include <cstdint>
#include <iostream>
#include "joker.h"
#include "tools.h"

const char COMMON = 0;
const char UNCOMMON = 1;
const char RARE = 2;
const char LEGENDARY = 3;

const char ON_PLAYED = 0;
const char ON_SCORED = 1;
const char ON_HELD = 2;
const char ON_INDEPENDENT = 3;

const char MAX_2BIT = 3;
const char MAX_3BIT = 5;


Joker::Joker(int activation_code, int rarity, int edition){
  data = 0;
  setRarity(rarity);
  setActivateOn(activation_code);
  setEdition(edition);
}

void Joker::set(int max, int value, int shift, uint8_t mask){
  if (!checkRange(max, value)){
    printError(OUT_OF_RANGE_ERROR); 
    return;
  } 
  clearAndSet(data, value, mask,shift);

}

std::string Joker::getDescription(){
  return description;
}

std::string Joker::getName(){
  return name;
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

uint8_t Joker::getData(){
  return data;
}


void Joker::setEdition(int edition){
  set(MAX_3BIT, edition, EDITION_SHIFT, EDITION_MASK);
}

void Joker::setRarity(int rarity){
  set(MAX_2BIT,rarity,RARITY_SHIFT,RARITY_MASK);
}
void Joker::setActivateOn(int activation_code){
  set(MAX_2BIT,activation_code,ACTIVATION_SHIFT,ACTIVATION_CODE_MASK);
}

void Joker::setDescription(std::string text){
  description = text;
}
void Joker::setName(std::string value){
  name = value;
}

void Joker::toString(){
  std::ostringstream oss;
  std::cout << "Joker [Activation Code: " << getActivatedOn()
        << ", Rarity: " << getRarity()
        << ", Edition: " << getEdition()
        << ", Data: " << static_cast<int>(data)
        << ", Description: " << getDescription() << "]\n";
}





int main (int argc, char *argv[]) {
  Joker joker(ON_HELD,LEGENDARY,FOIL);
  joker.setDescription("There was a joker whose name was joker");
  joker.toString();
}
