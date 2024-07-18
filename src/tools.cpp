
#include "tools.h"
#include <cstdint>
#include <iostream>
#include <ostream>

/* Simple method to see whether or not the value given is greater than, or equal to zero and at most the maximum value given */
bool checkRange(int max, int value) {
  return value >= 0 && value <= max;
}

/* Logger method, error messages can and should be defined in the indidual classes that use this */
void printError(std::string error) {
  std::cout << error << '\n';
}

/* set the bits of a variable, data is the template that gets operaterd upon, value is the value that should be added to it, mask is used to determine the amount of bits affected 
 * and shift determines which bits onwards get overriden  */
template <typename T>
void setBits(T& data, int value, uint16_t mask, int shift) {
  data |= (value << shift) & mask;
}

/* clears the bits of the data object using the given mask */
template <typename T>
void clearBits(T& data, uint16_t mask) {
  data &= ~mask;
}

/* compiles the clearBits and setBits methods into one method */
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
