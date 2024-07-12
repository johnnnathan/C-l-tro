#ifndef TOOLS_H
#define TOOLS_H

#include <iomanip>
#include <sstream>

int int_to_hex(int value);

bool checkRange(int min, int max, int value);

template <typename T>
void clearAndSet(T& data, T value, T mask, T shift);

template <typename T>
void clearBits(T& data, T mask);

template <typename T>
void setBits(T& data, T value, T mask, T shift);

#endif //TOOLS_H
