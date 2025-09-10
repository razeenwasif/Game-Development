package com.mycompany.app;

/**
 * Represents a monster in the game.
 */
public class Monster {
  private String name;
  private int hp;
  private int attackDamage;
  private int x;
  private int y;

  /**
   * Constructs a new Monster object.
   *
   * @param name The name of the monster.
   * @param hp The health points of the monster.
   * @param attackDamage The attack damage of the monster.
   * @param x The x-coordinate of the monster.
   * @param y The y-coordinate of the monster.
   */
  public Monster(
      String name, int hp, int attackDamage, int x, int y
      ) {
    this.name = name;
    this.hp = hp;
    this.attackDamage = attackDamage;
    this.x = x;
    this.y = y;
      }

  /**
   * Gets the name of the monster.
   *
   * @return The name of the monster.
   */
  public String getName() {
    return name;
  }

  /**
   * Gets the health points of the monster.
   *
   * @return The health points of the monster.
   */
  public int getHp() {
    return hp;
  }

  /**
   * Gets the attack damage of the monster.
   *
   * @return The attack damage of the monster.
   */
  public int getAttackDamage() {
    return attackDamage;
  }

  /**
   * Reduces the monster's health points by the given amount.
   *
   * @param damage The amount of damage to take.
   */
  public void takeDamage(int damage) {
    this.hp -= damage;
    if (this.hp < 0) {
      this.hp = 0;
    }
  }

  /**
   * Checks if the monster is alive.
   *
   * @return True if the monster is alive, false otherwise.
   */
  public boolean isAlive() {
    return this.hp > 0;
  }
}
