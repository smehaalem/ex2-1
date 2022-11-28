//
// Created by USER1 on 11/28/2022.
//

#include "Player.h"
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):m_status(GameStatus::MidGame),
                                                                                   m_player(playerName), m_numberOfCards(numOfCards), m_cardIndex(0) {
    for (int i = 0; i < numOfCards; ++i) {
        m_cards[i]= cardsArray[i];
    }

}

void Mtmchkin::playNextCard() {
    if (m_numberOfCards == 0)
        return;

    if (m_cardIndex >= m_numberOfCards)
        m_cardIndex = 0;

    Card card = m_cards[m_cardIndex];
    m_cardIndex += 1;
    card.printInfo();

    card.applyEncounter(m_player);
    m_player.printInfo();

    if (m_player.getLevel() >= 10)
        m_status = GameStatus::Win;
    else if (m_player.isKnockedOut())
        m_status = GameStatus::Loss;
}

bool Mtmchkin::isOver() const {
    if (m_status == GameStatus::Loss || m_status == GameStatus::Win)
        return true;
    return false;
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

Mtmchkin::~Mtmchkin() {
    delete[] m_cards;
}