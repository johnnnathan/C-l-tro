
#include "tools.h"
#include "playingCard.h"
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

template <typename T>
void setBits(T& data, T value, T mask, int shift){
  data |= (value << shift) & mask;
}

template <typename T>
void clearBits(T& data, T mask){
  data &= ~mask;
}

template void clearBits<uint8_t>(uint8_t& data, uint8_t mask);
template void setBits<uint8_t>(uint8_t& data, uint8_t value,  uint8_t mask,int shift);

template void clearBits<short int>(short int& data, short int mask);
template void setBits<short int>(short int& data, short int value, short int mask, int shift);
