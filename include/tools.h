
#ifndef TOOLS_H
#define TOOLS_H

#include "playingCard.h"
#include "points.h"
#include <array>

std::array<PlayingCard, 5> sortPlayingCards(std::array<PlayingCard, 5> array);

void add(int &basis, int value);
void subtract(int &basis, int value);
void multiply(int &basis, int value);
void divide(int &basis, int value);

bool isIn(std::array<int, 5> array, int number);

bool areIn(std::array<int, 5> given, std::array<int, 5> wanted);

int int_to_hex(int value);

bool checkRange(int max, int value);

void printError(std::string error);

void setPoints(Points &points, int mult, int chips);

template <typename T>
void clearAndSet(T &data, int value, uint16_t mask, int shift);

template <typename T> void clearBits(T &data, uint16_t mask);

template <typename T>
void setBits(T &data, int value, uint16_t mask, int shift);

#endif // TOOLS_H
