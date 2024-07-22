#include <iostream>
#include "hand.h"
#include "playingCard.h"

void testHighCard() {
    std::array<PlayingCard, 5> highCardHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(5, 2, 0, 0, 0),
        PlayingCard(9, 3, 0, 0, 0),
        PlayingCard(7, 1, 0, 0, 0),
        PlayingCard(12, 2, 0, 0, 0)
    };

    Hand hand(highCardHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::HIGH_CARD) {
        std::cout << "Test Passed: High Card detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testPair() {
    std::array<PlayingCard, 5> pairHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 2, 0, 0, 0),
        PlayingCard(9, 3, 0, 0, 0),
        PlayingCard(7, 1, 0, 0, 0),
        PlayingCard(12, 2, 0, 0, 0)
    };

    Hand hand(pairHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::ONE_PAIR) {
        std::cout << "Test Passed: One Pair detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testTwoPair() {
    std::array<PlayingCard, 5> twoPairHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 2, 0, 0, 0),
        PlayingCard(9, 3, 0, 0, 0),
        PlayingCard(9, 1, 0, 0, 0),
        PlayingCard(12, 2, 0, 0, 0)
    };

    Hand hand(twoPairHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::TWO_PAIR) {
        std::cout << "Test Passed: Two Pair detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testThreeOfAKind() {
    std::array<PlayingCard, 5> threeOfAKindHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 2, 0, 0, 0),
        PlayingCard(2, 3, 0, 0, 0),
        PlayingCard(7, 1, 0, 0, 0),
        PlayingCard(12, 2, 0, 0, 0)
    };

    Hand hand(threeOfAKindHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::THREE_OF_A_KIND) {
        std::cout << "Test Passed: Three of a Kind detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testStraight() {
    std::array<PlayingCard, 5> straightHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(3, 2, 0, 0, 0),
        PlayingCard(4, 3, 0, 0, 0),
        PlayingCard(5, 1, 0, 0, 0),
        PlayingCard(6, 2, 0, 0, 0)
    };

    Hand hand(straightHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::STRAIGHT) {
        std::cout << "Test Passed: Straight detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testFlush() {
    std::array<PlayingCard, 5> flushHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(5, 1, 0, 0, 0),
        PlayingCard(9, 1, 0, 0, 0),
        PlayingCard(7, 1, 0, 0, 0),
        PlayingCard(12, 1, 0, 0, 0)
    };

    Hand hand(flushHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::FLUSH) {
        std::cout << "Test Passed: Flush detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testFullHouse() {
    std::array<PlayingCard, 5> fullHouseHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 2, 0, 0, 0),
        PlayingCard(2, 3, 0, 0, 0),
        PlayingCard(7, 1, 0, 0, 0),
        PlayingCard(7, 2, 0, 0, 0)
    };

    Hand hand(fullHouseHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::FULL_HOUSE) {
        std::cout << "Test Passed: Full House detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testFourOfAKind() {
    std::array<PlayingCard, 5> fourOfAKindHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 2, 0, 0, 0),
        PlayingCard(2, 3, 0, 0, 0),
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(7, 2, 0, 0, 0)
    };

    Hand hand(fourOfAKindHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::FOUR_OF_A_KIND) {
        std::cout << "Test Passed: Four of a Kind detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testStraightFlush() {
    std::array<PlayingCard, 5> straightFlushHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(3, 1, 0, 0, 0),
        PlayingCard(4, 1, 0, 0, 0),
        PlayingCard(5, 1, 0, 0, 0),
        PlayingCard(6, 1, 0, 0, 0)
    };

    Hand hand(straightFlushHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::STRAIGHT_FLUSH) {
        std::cout << "Test Passed: Straight Flush detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testRoyalFlush() {
    std::array<PlayingCard, 5> royalFlushHand = {
        PlayingCard(10, 1, 0, 0, 0),
        PlayingCard(11, 1, 0, 0, 0),
        PlayingCard(12, 1, 0, 0, 0),
        PlayingCard(9, 1, 0, 0, 0),
        PlayingCard(0, 1, 0, 0, 0)
    };

    Hand hand(royalFlushHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::ROYAL_FLUSH) {
        std::cout << "Test Passed: Royal Flush detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testFiveOfAKind() {
    std::array<PlayingCard, 5> fiveOfAKindHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 2, 0, 0, 0),
        PlayingCard(2, 3, 0, 0, 0),
        PlayingCard(2, 0, 0, 0, 0),
        PlayingCard(2, 1, 0, 0, 0)
    };

    Hand hand(fiveOfAKindHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::FIVE_OF_A_KIND) {
        std::cout << "Test Passed: Five of a Kind detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testFlushHouse() {
    std::array<PlayingCard, 5> flushHouseHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(7, 1, 0, 0, 0),
        PlayingCard(7, 1, 0, 0, 0)
    };

    Hand hand(flushHouseHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::FLUSH_HOUSE) {
        std::cout << "Test Passed: Flush House detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
    }
}

void testFlushFive() {
    std::array<PlayingCard, 5> flushFiveHand = {
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 1, 0, 0, 0),
        PlayingCard(2, 1, 0, 0, 0)
    };

    Hand hand(flushFiveHand, 1, 100);
    auto result = hand.evaluate();

    if (result.first == HandType::FLUSH_FIVE) {
        std::cout << "Test Passed: Flush Five detected." << std::endl;
    } else {
        std::cout << "Test Failed: Incorrect hand type detected." << std::endl;
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
    testStraightFlush();
    testRoyalFlush();
    testFiveOfAKind();
    testFlushHouse();
    testFlushFive();
    return 0;
}
