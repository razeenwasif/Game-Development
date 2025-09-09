package com.mycompany.app;

public class Monster {
  private String name;
  private int hp;
  private int attackDamage;
  private int x;
  private int y;

  public Monster(
      String name, int hp, int attackDamage, int x, int y
      ) {
    this.name = name;
    this.hp = hp;
    this.attackDamage = attackDamage;
    this.x = x;
    this.y = y;
      }

  public String getName() {
    return name;
  }

  public int getHp() {
    return hp;
  }

  public int getAttackDamage() {
    return attackDamage;
  }

  public void takeDamage(int damage) {
    this.hp -= damage;
    if (this.hp < 0) {
      this.hp = 0;
    }
  }

  public boolean isAlive() {
    return this.hp > 0;
  }
}
