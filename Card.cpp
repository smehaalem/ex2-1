//
// Created by USER1 on 11/28/2022.
//

#include "utilities.h"
#include "Card.h"

Card::Card(CardType type, const CardStats &stats) :m_effect(type), m_stats(stats){
}

void Card::applyEncounter(Player &player) const {
    switch (m_effect) {
        case CardType::Battle: {
            int strength = player.getAttackStrength();
            if (strength < m_stats.force) {
                // The monster is stronger than the player, the player looses battle.
                player.damage(m_stats.hpLossOnDefeat);
                printBattleResult(false);
            }
            else {
                // The player is stronger than the monster, the player winns battle.
                player.addCoins(m_stats.loot);
                player.levelUp();
                printBattleResult(true);
            }
            break;
        } case CardType::Buff: {
            if (player.pay(m_stats.cost))
                player.buff(m_stats.buff);
            break;
        } case CardType::Heal: {
            if (player.pay(m_stats.cost))
                player.heal(m_stats.heal);
            break;
        } case CardType::Treasure: {
            player.addCoins(m_stats.loot);
            break;
        } default: {
            // Handle any other case that wasn't stated at the time.
            break;
        }
    }
}


void Card::printInfo() const {
    switch (m_effect) {
        case CardType::Battle: {
            printBattleCardInfo(m_stats);
            break;
        } case CardType::Buff: {
            printBuffCardInfo(m_stats);
            break;
        } case CardType::Heal: {
            printHealCardInfo(m_stats);
            break;
        } case CardType::Treasure: {
            printTreasureCardInfo(m_stats);
            break;
        } default: {
            // Handle any other case that wasn't stated at the time.
            break;
        }
    }
}

