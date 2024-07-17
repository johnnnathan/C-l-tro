
#include "tools.h"
#include <cstdint>
#include <iostream>
#include <ostream>

bool checkRange(int max, int value) {
  return value >= 0 && value <= max;
}

void printError(std::string error) {
  std::cout << error << '\n';
}

template <typename T>
void setBits(T& data, int value, uint16_t mask, int shift) {
  data |= (value << shift) & mask;
}

template <typename T>
void clearBits(T& data, uint16_t mask) {
  data &= ~mask;
}

template <typename T>
void clearAndSet(T& data, int value, uint16_t mask, int shift) {
  clearBits(data, mask);
  setBits(data, value, mask, shift);
}

template void clearAndSet<uint8_t>(uint8_t& data, int value, uint16_t mask, int shift);
template void clearAndSet<short int>(short int& data, int value, uint16_t mask, int shift);
template void clearAndSet<unsigned short>(unsigned short& data, int value, uint16_t mask, int shift);

template void clearBits<uint8_t>(uint8_t& data, uint16_t mask);
template void setBits<uint8_t>(uint8_t& data, int value, uint16_t mask, int shift);

template void clearBits<short int>(short int& data, uint16_t mask);
template void setBits<short int>(short int& data, int value, uint16_t mask, int shift);

template void clearBits<unsigned short>(unsigned short& data, uint16_t mask);
template void setBits<unsigned short>(unsigned short& data, int value, uint16_t mask, int shift);
