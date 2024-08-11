#include "shop.h"
#include "cardProperties.h"
#include "joker.h"
#include "jokerDeck.h"
#include "playingCard.h"
#include "tools.h"
#include <array>
#include <sstream>
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
  seal = std::make_pair(Seal::NO_SEAL, 2);
  enhancement = std::make_pair(Enhancement::NO_ENHANCEMENT, 2);
  edition = std::make_pair(Edition::NO_EDITION_CARD, 2);
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
  seal.first = static_cast<Seal>(randomIndex);
  seal.second = 2;
}

void Shop::setEdition() {
  int randomIndex = std::rand() % 4;
  edition.first = static_cast<Edition>(randomIndex);
  edition.second = 2;
}

void Shop::setEnhancement() {
  int randomIndex = std::rand() % 9;
  enhancement.first = static_cast<Enhancement>(randomIndex);
  enhancement.second = 2;
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
  std::cout << "Enhancement : " << enhancementToString(enhancement.first)
            << " Price : 2$\n\n";

  std::cout << "Seal : " << sealToString(seal.first) << " Price : 3$\n\n";
  std::cout << "Edition : " << editionToString(edition.first)
            << " Price : 4$\n\n";
}

std::tuple<char, char, int> Shop::getInput(bool &shouldExit) {
  std::string input;
  char action = ' ';
  char type = ' ';
  int index = -1;

  std::cout << "Enter action ('b' to buy, 'q' to quit), type ('j' for joker, "
               "'p' for playing card, 's' for seal, 'e' for edition, 'h' for "
               "enhancement), and index (0-2 for joker/card) or ID of card : ";
  std::getline(std::cin, input);

  if (input == "q") {
    shouldExit = true;
    return {action, type, index};
  }

  std::istringstream stream(input);
  stream >> action;

  if (action == 'b') {
    stream >> type;
    stream >> index;
  }

  return {action, type, index};
}

void Shop::buy(int &money, JokerDeck &jdeck, Deck &deck) {
  print();
  while (true) {

    bool shouldExit = false;
    std::tuple<char, char, int> purchaseData = getInput(shouldExit);
    if (shouldExit) {
      break;
    }
    char action = std::get<0>(purchaseData);
    char type = std::get<1>(purchaseData);
    int indexOrID = std::get<2>(purchaseData);
    bool transactionMade;
    PlayingCard *card;
    switch (type) {
    case 'j':
      checkRange(3, indexOrID);
      if (!boughtJoker[indexOrID]) {
        bool transactionMade = makeTransaction(money, jokers[indexOrID].second);
        if (!transactionMade) {
          break;
        }
        jdeck.addJoker(jokers[indexOrID].first);
        boughtJoker[indexOrID] = true;
        break;
      }

    case 'c':
      checkRange(3, indexOrID);
      if (cards[indexOrID].first->getID() != 0) {
        transactionMade = makeTransaction(money, cards[indexOrID].second);
        if (!transactionMade) {
          break;
        }
        deck.addCard(cards[indexOrID].first);
        cards[indexOrID].first = new PlayingCard(0);
        break;
      }

    case 's':
      transactionMade = makeTransaction(money, seal.second);
      if (!transactionMade) {
        break;
      }
      card = deck.getCard(indexOrID);
      card->setSeal(seal.first);
      card->print();
      break;

    case 'e':
      transactionMade = makeTransaction(money, edition.second);
      if (!transactionMade) {
        break;
      }
      card = deck.getCard(indexOrID);
      card->setEdition(edition.first);
      card->print();
      break;

    case 'h':
      transactionMade = makeTransaction(money, enhancement.second);
      if (!transactionMade) {
        break;
      }
      card = deck.getCard(indexOrID);
      card->setEnhancement(enhancement.first);
      card->print();
      break;
    default:
      printf("Something went wrong");
    }
  }
}

bool Shop::makeTransaction(int &money, int cost) {
  if (money < cost) {
    return false;
  }
  money -= cost;
  return true;
}
