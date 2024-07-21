#include "playingCard.h"
#include "tools.h"


int main() {
    // Create an array of PlayingCard objects
    std::array<PlayingCard, 5> cards = {
        PlayingCard(12, 1, 5, 2, 3), // Rank: 12 (Queen), Suit: 1, Enhancement: 5, Edition: 2, Seal: 3
        PlayingCard(3, 2, 7, 1, 1),  // Rank: 3, Suit: 2, Enhancement: 7, Edition: 1, Seal: 1
        PlayingCard(14, 0, 4, 3, 2), // Rank: 14 (Ace), Suit: 0, Enhancement: 4, Edition: 3, Seal: 2
        PlayingCard(5, 3, 8, 0, 0),  // Rank: 5, Suit: 3, Enhancement: 8, Edition: 0, Seal: 0
        PlayingCard(9, 1, 2, 2, 4)   // Rank: 9, Suit: 1, Enhancement: 2, Edition: 2, Seal: 4
    };

    // Print original array
    std::cout << "Original array of playing cards:\n";
    for (const auto& card : cards) {
        std::cout << card << '\n';
    }

    // Sort the array of playing cards
    cards = sortPlayingCards(cards);

    // Print sorted array
    std::cout << "\nSorted array of playing cards by rank (ascending order):\n";
    for (const auto& card : cards) {
        std::cout << card << '\n';
    }

    return 0;
}
