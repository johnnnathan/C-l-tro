
#ifndef TOOLS_H
#define TOOLS_H

#include "playingCard.h"
#include <iomanip>
#include <sstream>
#include <array>

std::array<PlayingCard, 5> sortPlayingCards(std::array<PlayingCard, 5> array);

int int_to_hex(int value);

bool checkRange(int max, int value);

void printError(std::string error);

template <typename T>
void clearAndSet(T& data, int value, uint16_t mask, int shift);

template <typename T>
void clearBits(T& data, uint16_t mask);

template <typename T>
void setBits(T& data, int value, uint16_t mask, int shift);

#endif // TOOLS_H
