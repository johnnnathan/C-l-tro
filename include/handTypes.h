#ifndef HANDTYPES_H
#define HANDTYPES_H

enum class HandType {
  HIGH_CARD = 0,
  ONE_PAIR = 1,
  TWO_PAIR = 2,
  THREE_OF_A_KIND = 3,
  STRAIGHT = 4,
  FLUSH = 5,
  FULL_HOUSE = 6,
  FOUR_OF_A_KIND = 7,
  STRAIGHT_FLUSH = 8,
  ROYAL_FLUSH = 9,
  FIVE_OF_A_KIND = 10,
  FLUSH_HOUSE = 11,
  FLUSH_FIVE = 12,
  ERROR = -1,

};

#endif // HANDTYPES_H
