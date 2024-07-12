
#include "tools.h"
#include "playingCard.h"
#include <cstdint>
#include <iomanip>
#include <sstream>

int int_to_hex(int value);

int int_to_hex(int value){
  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(value);
  std::string hexString = ss.str();
  int mask;
  std::istringstream(hexString) >> std::hex >> mask;
  return mask;
}

bool checkRange(int min, int max, int value){
  if (value < min || value > max) return false;
  return true;
}

void printError(std::string error){
  std::cout << error << '\n';

}

template <typename T>
void clearAndSet(T& data, int value, uint8_t mask, int shift){
  clearBits(data, mask);
  setBits(data,value,mask,shift);
}


template <typename T>
void setBits(T& data, int value, uint8_t mask, int shift){
  data |= (value << shift) & mask;
}

template <typename T>
void clearBits(T& data, uint8_t mask){
  data &= ~mask;
}

template void clearAndSet<uint8_t>(uint8_t& data, int value, uint8_t mask, int shift);
template void clearAndSet<short int>(short int& data, int value, uint8_t mask, int shift);

template void clearBits<uint8_t>(uint8_t& data, uint8_t mask);
template void setBits<uint8_t>(uint8_t& data, int value,  uint8_t mask,int shift);

template void clearBits<short int>(short int& data, uint8_t mask);
template void setBits<short int>(short int& data, int value, uint8_t mask, int shift);
