#ifndef J_EFFECT_H
#define J_EFFECT_H

enum class Operation {
  ADD,
  SUBTRACT,
  MULTIPLY,
  ADD_CARD,
  GIVE_SCORE,
  GIVE_ENHANCEMENT,
};

enum class Target {
  NONE,
  CHIPS,
  MULTIPLIER,
  MONEY,
  CARD,
};

enum class Filter {
  NONE,
  EVEN,
  ODD,
  FACE,
  ACE,
  CLUBS,
  SPADES,
  HEARTS,
  DIAMONDS,
};

struct Effect {
  Operation operation;
  Target target;
  Filter filter;
  unsigned char quantity;
};

#endif // !J_EFFECT_H
