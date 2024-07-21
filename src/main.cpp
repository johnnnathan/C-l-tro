#include "playingCard.h"
#include "hand.h"
#include <iostream>
#include <array>

int HEARTS = 0;
int CLUBS = 1;
int DIAMONDS = 2;
int SPADES = 3;

void testHighCard() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(2, HEARTS, 0, 0, 0),
        PlayingCard(4, CLUBS, 0, 0, 0),
        PlayingCard(6, DIAMONDS, 0, 0, 0),
        PlayingCard(8, SPADES, 0, 0, 0),
        PlayingCard(10, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isHighCard()) {
        std::cout << "HighCard test passed\n";
    } else {
        std::cout << "HighCard test failed\n";
    }
}

void testPair() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(2, HEARTS, 0, 0, 0),
        PlayingCard(2, CLUBS, 0, 0, 0),
        PlayingCard(6, DIAMONDS, 0, 0, 0),
        PlayingCard(8, SPADES, 0, 0, 0),
        PlayingCard(10, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isPair()) {
        std::cout << "Pair test passed\n";
    } else {
        std::cout << "Pair test failed\n";
    }
}

void testTwoPair() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(2, HEARTS, 0, 0, 0),
        PlayingCard(2, CLUBS, 0, 0, 0),
        PlayingCard(6, DIAMONDS, 0, 0, 0),
        PlayingCard(6, SPADES, 0, 0, 0),
        PlayingCard(10, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isTwoPair()) {
        std::cout << "TwoPair test passed\n";
    } else {
        std::cout << "TwoPair test failed\n";
    }
}

void testThreeOfAKind() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(2, HEARTS, 0, 0, 0),
        PlayingCard(2, CLUBS, 0, 0, 0),
        PlayingCard(2, DIAMONDS, 0, 0, 0),
        PlayingCard(8, SPADES, 0, 0, 0),
        PlayingCard(10, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isThreeOfAKind()) {
        std::cout << "ThreeOfAKind test passed\n";
    } else {
        std::cout << "ThreeOfAKind test failed\n";
    }
}

void testStraight() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(6, HEARTS, 0, 0, 0),
        PlayingCard(7, CLUBS, 0, 0, 0),
        PlayingCard(8, DIAMONDS, 0, 0, 0),
        PlayingCard(9, SPADES, 0, 0, 0),
        PlayingCard(10, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isStraight()) {
        std::cout << "Straight test passed\n";
    } else {
        std::cout << "Straight test failed\n";
    }
}

void testFlush() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(2, HEARTS, 0, 0, 0),
        PlayingCard(4, HEARTS, 0, 0, 0),
        PlayingCard(6, HEARTS, 0, 0, 0),
        PlayingCard(8, HEARTS, 0, 0, 0),
        PlayingCard(10, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isFlush()) {
        std::cout << "Flush test passed\n";
    } else {
        std::cout << "Flush test failed\n";
    }
}

void testFullHouse() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(2, HEARTS, 0, 0, 0),
        PlayingCard(2, CLUBS, 0, 0, 0),
        PlayingCard(2, DIAMONDS, 0, 0, 0),
        PlayingCard(8, SPADES, 0, 0, 0),
        PlayingCard(8, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isFullHouse()) {
        std::cout << "FullHouse test passed\n";
    } else {
        std::cout << "FullHouse test failed\n";
    }
}

void testFourOfAKind() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(2, HEARTS, 0, 0, 0),
        PlayingCard(2, CLUBS, 0, 0, 0),
        PlayingCard(2, DIAMONDS, 0, 0, 0),
        PlayingCard(2, SPADES, 0, 0, 0),
        PlayingCard(10, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isFourOfAKind()) {
        std::cout << "FourOfAKind test passed\n";
    } else {
        std::cout << "FourOfAKind test failed\n";
    }
}

void testFiveOfAKind() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(2, HEARTS, 0, 0, 0),
        PlayingCard(2, CLUBS, 0, 0, 0),
        PlayingCard(2, DIAMONDS, 0, 0, 0),
        PlayingCard(2, SPADES, 0, 0, 0),
        PlayingCard(2, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isFiveOfAKind()) {
        std::cout << "FiveOfAKind test passed\n";
    } else {
        std::cout << "FiveOfAKind test failed\n";
    }
}

void testStraightFlush() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(6, HEARTS, 0, 0, 0),
        PlayingCard(7, HEARTS, 0, 0, 0),
        PlayingCard(8, HEARTS, 0, 0, 0),
        PlayingCard(9, HEARTS, 0, 0, 0),
        PlayingCard(10, HEARTS, 0, 0, 0)
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isStraightFlush()) {
        std::cout << "StraightFlush test passed\n";
    } else {
        std::cout << "StraightFlush test failed\n";
    }
}

void testRoyalFlush() {
    std::array<PlayingCard, 5> cards = {
        PlayingCard(10, HEARTS, 0, 0, 0),
        PlayingCard(11, HEARTS, 0, 0, 0),
        PlayingCard(12, HEARTS, 0, 0, 0),
        PlayingCard(13, HEARTS, 0, 0, 0),
        PlayingCard(1, HEARTS, 0, 0, 0) // Assuming 1 represents Ace
    };
    Hand hand(cards, 1, 100);
    hand.findPairs();
    if (hand.isRoyalFlush()) {
        std::cout << "RoyalFlush test passed\n";
    } else {
        std::cout << "RoyalFlush test failed\n";
    }
}

int main() {
    testHighCard();
    testPair();
    testTwoPair();
    testThreeOfAKind();
    testStraight();
    testFlush();
    testFullHouse();
    testFourOfAKind();
    testFiveOfAKind();
    testStraightFlush();
    testRoyalFlush();

    return 0;
}
/*
int main() {
    // Create an array of PlayingCard objects
    std::array<PlayingCard, 5> cards = {
        PlayingCard(12, 1, 5, 2, 3), // Rank: 12 (Queen), Suit: 1, Enhancement: 5, Edition: 2, Seal: 3
        PlayingCard(3, 2, 7, 1, 1),  // Rank: 3, Suit: 2, Enhancement: 7, Edition: 1, Seal: 1
        PlayingCard(1, 0, 4, 3, 2), // Rank: 14 (Ace), Suit: 0, Enhancement: 4, Edition: 3, Seal: 2
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
*/
