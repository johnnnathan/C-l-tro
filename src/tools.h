#ifndef TOOLS_H
#define TOOLS_H

#include <iomanip>
#include <sstream>


const int8_t NO_EDITION = 1;
const int8_t FOIL = 2;
const int8_t HOLOGRAPHIC = 3;
const int8_t POLYCHROME = 4;
const int8_t NEGATIVE = 5;


int int_to_hex(int value);

bool checkRange(int min, int max, int value);

void printError(std::string error);

template <typename T>
void clearAndSet(T& data, int value, uint8_t mask, int shift);

template <typename T>
void clearBits(T& data, uint8_t mask);

template <typename T>
void setBits(T& data, int value, uint8_t mask, int shift);

#endif //TOOLS_H
