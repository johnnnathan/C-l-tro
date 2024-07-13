#ifndef TOOLS_H
#define TOOLS_H

#include <iomanip>
#include <sstream>


const char NO_EDITION = 1;
const char FOIL = 2;
const char HOLOGRAPHIC = 3;
const char POLYCHROME = 4;
const char NEGATIVE = 5;


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
