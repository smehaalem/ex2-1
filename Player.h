//
// Created by USER1 on 11/28/2022.
//

#ifndef EX2_1_PLAYER_H
#define EX2_1_PLAYER_H
#include <string>

#define DEFAULT_MAX_HEALTH 100
#define DEFAULT_FORCE 5

#endif //EX2_1_PLAYER_H

class Player{
    std::string m_name;
    int m_maxHp;
    int m_health;
    int m_force;
    int m_coins;
    int m_level;


public:
    /*
     * Constructor of Player class
     *
     * @param name - The name of the player.
     * @param maxHp - The maximum HP of the player, The default HP is 100.
     * @param force - The initial force of the player, The default force is 5 Points.
     * @return
     *      A new instance of Player.
     */

    Player(const std::string name, int maxHp = DEFAULT_MAX_HEALTH, int force = DEFAULT_FORCE);

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */

    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

    /*
      * Prints the player info:
      *
      * @return
      *      void
     */
    void printInfo() const;

    /*
     * increase the player level by 1 up to the max level
     * @return
     *     void
     */
    void levelUp();

    /*
     * returns the current level of the player
     *
     * @return
     *  the player level(int)
     */
    int getLevel() const;

    /*
     * adds the given amount of force to the player force
     *  * @param force - The amount of force points to add to player's force.
     * @return
     *      void
     */
    void buff(int force);

    /*
     * adds the given amount to the player health points.
     * * @param hp - The amount of health points to add to player's health (hp).
     * @return
     *      void
     */
    void heal(int hp);

    /*
     * decrease the given amount of health point from the player's health points
     ** @param HP - The amount of health points to remove from player's health (hp).
     * @return
     *    void
     */
    void damage(int hp);

    /*
     * checks if the player's health points are 0
     *  @return
     *    true(if the HP are 0) or false if not
     */
    bool isKnockedOut() const;

    /*
     * adds the given amount of coins to the player's coins
     * @param coins - the amount of coins to add to the player's coins
     * @return
     *     void
     */
    void addCoins(int coins);

    /*
    * deducts the said amount of coins out of the receiver's `fortune` if the
    * player can afford the transaction, othwerise does nothing.
    *
    * @param price - The amount (price) to deduct out of the player's fortune.
    * return
    *      `true` if transaction is valid the amount was deducted, otherwise `false`.
    */
    bool pay(int price);

    /*
    * Returns attack strength of the receiver (player).
    *
    * @return
    *      The attack strength of the player.
    */
    int getAttackStrength() const;

};