//
// Created by USER1 on 11/28/2022.
//

#include "utilities.h"
#include "Player.h"

#define MAX_LEVEL 10
#define DEFAULT_MAX_HP 100
#define DEFAULT_FORCE 5
#define DEFAULT_COINS 0



Player::Player(const std::string name, int maxHp, int force):m_name(name), m_maxHp(maxHp), m_health(maxHp),
                                   m_force(force), m_coins(0), m_level(1) {
    if(m_force < 0)
        m_force = DEFAULT_FORCE;

    if(m_coins < 0)
        m_coins = DEFAULT_COINS;

    if(maxHp < 0)
        m_maxHp = DEFAULT_MAX_HP;

    if(m_health > m_maxHp)
        m_health = m_maxHp;

    if(m_health < 0)
        m_health = 0;

}


void Player::printInfo() const {
    printPlayerInfo(m_name.c_str(),m_level,m_force,m_health,m_coins);
}


void Player::levelUp() {
    if(m_level >= MAX_LEVEL)
        return;

    m_level +=1;
}


int Player::getLevel() const {
    return m_level;
}

void Player::buff(int force) {
    if(force <= 0)
        return;
    m_force += force;
}


void Player::heal(int hp) {
    if(hp <= 0)
        return;
    if(m_health == m_maxHp)
        return;
    if(m_health + hp >= m_maxHp)
    {
        m_health = m_maxHp;
        return;
    }
    m_health += hp;
}


void Player::damage(int hp) {
    if(hp <= 0 || m_health == 0)
        return;
    if(m_health - hp <= 0)
    {
        m_health = 0;
        return;
    }
    m_health -= hp;
}


bool Player::isKnockedOut() const {
    return (m_health <= 0);
}

void Player::addCoins(int coins) {
    if(coins <= 0)
        return;

    m_coins += coins;
}

bool Player::pay(int price) {
    if (price <= 0)
        return true;
    if(m_coins < price)
        return false;
    else
        m_coins -= price;
    return true;
}


int Player::getAttackStrength() const {
    return m_health + m_level;
}