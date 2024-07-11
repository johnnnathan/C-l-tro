#include "tools.h"
#include <cstdint>
#include <iostream>
#include "joker.h"

const uint8_t EDITION_MASK = 0b11100000;
const uint8_t RARITY_MASK = 0b00001100;
const uint8_t ACTIVATION_CODE_MASK = 0b00000011;

Joker::Joker(int activation_code, int rarity, int edition){
  data = 0;
  setRarity(rarity);
  setActivateOn(activation_code);
  setEdition(edition);
}
void Joker::setEdition(int edition){
  if (edition < 1 || edition > 5){
    return;
  }
  data &= ~EDITION_MASK;
  data |= (edition << 5);

}

std::string Joker::getDescription(){
  return description;
}
int Joker::getEdition(){
  return (data >> 5) & 0b111;
} 

int Joker::getRarity(){
  return (data >> 2) & 0b11;
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
  if (rarity < 1||rarity > 4){
    return;
  }
  data &= ~RARITY_MASK;
  data |= (rarity << 2);
}
void Joker::setActivateOn(int activation_code){
  if (activation_code < 1 || activation_code > 5){
    return;
  }
  data &= ~ACTIVATION_CODE_MASK;
  data |= (activation_code & ACTIVATION_CODE_MASK);
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
