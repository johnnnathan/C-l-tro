
#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <cstdint>
#include <string>
#include <iostream>
#include <cstdio>

const char NO_ENHANCEMENT = 0;
const char BONUS = 1;
const char MULT = 2;
const char WILD = 3;
const char GLASS = 4;
const char STEEL = 5;
const char STONE = 6;
const char GOLD = 7;
const char LUCKY = 8;

const char NO_SEAL = 0;
const char GOLD_SEAL = 1;
const char RED_SEAL = 2;
const char BLUE_SEAL = 3;
const char PURPLE_SEAL = 4;

const char NO_EDITION = 0;

void setError(std::string valueType, int rangeEnd);

class PlayingCard {
private:
    int id;
    unsigned short int data; // From left to right: Suit 2 bits / Rank 4 bits / Enhancement 4 bits / Edition 3 bits / Seal 3 bits
    uint8_t score;
public:
    void setSuit(int8_t suit);
    void setRank(int8_t rank);
    void setEnhancement(int8_t enhancement);
    void setEdition(int8_t edition);
    void setSeal(int8_t seal);
    void setScore(int8_t score);
    void set(int max, int value, int shift, uint16_t mask);
    int getID();
    int8_t getSuit() const;
    int8_t getRank() const;
    int8_t getEnhancement() const;
    int8_t getEdition() const;
    int8_t getSeal() const;
    PlayingCard(int8_t rank, int8_t suit, int8_t enhancement, int8_t edition, int8_t seal);
    unsigned short int getData();
    friend std::ostream& operator<<(std::ostream& os, const PlayingCard& card);
    std::string toString() const;
    void print();
};

#endif
