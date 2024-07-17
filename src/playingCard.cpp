#include "tools.h"
#include "playingCard.h"

int globalID = 0;

const int SUIT_SHIFT = 14;
const int RANK_SHIFT = 10;
const int ENHANCEMENT_SHIFT = 6;
const int EDITION_SHIFT = 3;
const int SEAL_SHIFT = 0;

const uint16_t BIT_2MASK = 0x3; // 2-bit mask
const uint16_t BIT_3MASK = 0x7; // 3-bit mask
const uint16_t BIT_4MASK = 0xF; // 4-bit mask

std::ostream& operator<<(std::ostream& os, const PlayingCard& card) {
    os << "Rank: " << static_cast<int>(card.getRank())
       << " Suit: " << static_cast<int>(card.getSuit())
       << " Enhancement: " << static_cast<int>(card.getEnhancement())
       << " Edition: " << static_cast<int>(card.getEdition())
       << " Seal: " << static_cast<int>(card.getSeal());
    return os;
}

std::string PlayingCard::toString() const {
    std::stringstream ss;
    ss << "Rank: " << static_cast<int>(getRank())
       << " Suit: " << static_cast<int>(getSuit())
       << " Enhancement: " << static_cast<int>(getEnhancement())
       << " Edition: " << static_cast<int>(getEdition())
       << " Seal: " << static_cast<int>(getSeal());
    return ss.str();
}

void PlayingCard::print() {
    std::string result = toString();
    std::cout << result << '\n';
}

PlayingCard::PlayingCard(int8_t rank, int8_t suit, int8_t enhancement, int8_t edition, int8_t seal) {
    id = globalID; // Increment globalID and assign it to id
    globalID += 1;
    data = 0; // Initialize data

    setRank(rank);
    setSuit(suit);
    setEnhancement(enhancement);
    setEdition(edition);
    setSeal(seal);
}

int PlayingCard::getID() {
    return id;
}

void PlayingCard::set(int max, int value, int shift, uint16_t mask) {
    if (!checkRange(max, value)) {
        printError("Value out of range");
        return;
    }
    clearAndSet(data, value, mask << shift, shift);
}

void PlayingCard::setSuit(int8_t suit) {
    set(3, suit, SUIT_SHIFT, BIT_2MASK);
}

void PlayingCard::setRank(int8_t rank) {
    set(12, rank, RANK_SHIFT, BIT_4MASK);
}

void PlayingCard::setEnhancement(int8_t enhancement) {
    set(8, enhancement, ENHANCEMENT_SHIFT, BIT_4MASK);
}

void PlayingCard::setEdition(int8_t edition) {
    set(3, edition, EDITION_SHIFT, BIT_3MASK);
}

void PlayingCard::setSeal(int8_t seal) {
    set(4, seal, SEAL_SHIFT, BIT_3MASK);
}

int8_t PlayingCard::getSuit() const {
    return (data >> SUIT_SHIFT) & BIT_2MASK;
}

int8_t PlayingCard::getRank() const {
    return (data >> RANK_SHIFT) & BIT_4MASK;
}

int8_t PlayingCard::getEnhancement() const {
    return (data >> ENHANCEMENT_SHIFT) & BIT_4MASK;
}

int8_t PlayingCard::getEdition() const {
    return (data >> EDITION_SHIFT) & BIT_3MASK;
}

int8_t PlayingCard::getSeal() const {
    return data & BIT_3MASK;
}
