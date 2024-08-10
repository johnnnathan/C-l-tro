#include "shop.h"
#include "cardProperties.h"
#include "joker.h"
#include "playingCard.h"
#include <array>
#include <utility>

Shop::Shop() {
  for (auto &card : cards) {
    card.first = nullptr; // Initialize pointer to nullptr
    card.second = 0;      // Default quantity to 0
  }

  // Initialize the jokers array
  for (auto &joker : jokers) {
    Joker jokerElement(0, 0, 0,
                       Effect{}); // Initialize Joker with default values
    joker.first = &jokerElement;
    joker.second = 0; // Default quantity to 0
  }

  // Initialize Seal, Enhancement, and Edition with default values
  seal = Seal::NO_SEAL;
  enhancement = Enhancement::NO_ENHANCEMENT;
  edition = Edition::NO_EDITION_CARD;
}
Shop::~Shop() {
  for (auto &card : cards) {
    delete card.first; // Free the memory
  }

  for (auto &joker : jokers) {
    delete joker.first; // Free the memory
  }
}
void Shop::setPlayingCards() {
  for (int i = 0; i < 3; i++) {
    cards[i].first = new PlayingCard(0);
    cards[i].second = 3;
  }
}
// placeholder method, will probably have to create a database or save them some
// other way, txt could be an option
void Shop::setJokers() {
  // Joker 1: Adds chips when activated, no filter applied
  Effect effect1;
  effect1.operation = Operation::ADD;
  effect1.target = Target::CHIPS;
  effect1.filter = Filter::NONE;
  effect1.quantity = 10; // Adds 10 chips

  Joker joker1(1, 2, 1, effect1); // Activation code 1, rarity 2, edition 1
  joker1.setName("Chip Master");
  joker1.setDescription("Adds 10 chips to your total when activated.");

  // Joker 2: Multiplies money on even cards
  Effect effect2;
  effect2.operation = Operation::MULTIPLY;
  effect2.target = Target::MONEY;
  effect2.filter = Filter::EVEN;
  effect2.quantity = 2; // Multiplies money by 2

  Joker joker2(2, 3, 2, effect2); // Activation code 2, rarity 3, edition 2
  joker2.setName("Even Multiplier");
  joker2.setDescription("Doubles your money when an even card is drawn.");

  // Joker 3: Gives a score for face cards
  Effect effect3;
  effect3.operation = Operation::GIVE_SCORE;
  effect3.target = Target::CHIPS;
  effect3.filter = Filter::FACE;
  effect3.quantity = 5; // Gives 5 points for face cards

  Joker joker3(3, 1, 3, effect3); // Activation code 3, rarity 1, edition 3
  joker3.setName("Face Card Scorer");
  joker3.setDescription("Gives 5 points for each face card (J, Q, K) drawn.");

  // Assign Jokers to the array with their associated quantity
  jokers[0] = std::make_pair(&joker1, 1); // 1 quantity of joker1
  jokers[1] = std::make_pair(&joker2, 1); // 1 quantity of joker2
  jokers[2] = std::make_pair(&joker3, 1); // 1 quantity of joker3
}
void Shop::setSeal() {
  int randomIndex = std::rand() % 5;
  seal = static_cast<Seal>(randomIndex);
}

void Shop::setEdition() {
  int randomIndex = std::rand() % 4;
  edition = static_cast<Edition>(randomIndex);
}

void Shop::setEnhancement() {
  int randomIndex = std::rand() % 9;
  enhancement = static_cast<Enhancement>(randomIndex);
}

void Shop::set() {
  setPlayingCards();
  setJokers();
  setSeal();
  setEnhancement();
  setEdition();
}

void Shop::print() {
  for (auto card : cards) {
    card.first->print();
    std::cout << "Price of Card: " << card.second << "$\n";
  }
  std::cout << '\n';
  for (auto joker : jokers) {
    joker.first->toString();
    std::cout << "Price of Joker: " << joker.second << "$\n";
  }
  std::cout << '\n';
  std::cout << "Enhancement : " << enhancementToString(enhancement)
            << " Price : 2$\n\n";

  std::cout << "Seal : " << sealToString(seal) << " Price : 3$\n\n";
  std::cout << "Edition : " << editionToString(edition) << " Price : 4$\n\n";
}
