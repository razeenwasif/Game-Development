package com.mycompany.app;

import java.util.ArrayList;
import java.util.List;

public class Player {
  private String name;
  private int hp;
  //position
  private int x;
  private int y;
  private Inventory inventory;

  public Player(String name, int hp) {
    this.name = name;
    this.hp = hp;
    this.x = x;
    this.y = y;
    this.inventory = new Inventory(10);
  }
  
  // Getter for HP
  public int getHp() {
    return this.hp;
  }

  // Setter for HP 
  public void setHp(int newHp) {
    if (newHp < 0) {
      this.hp = 0;
    } else {
      this.hp = newHp;
    }
  }

  // Getter for Inventory
  public Inventory getInventory() {
    return this.inventory;
  }

  // player move method 
  public String move(Direction direction) {
    // logic to check if player can move in that direction 
    if (canMove(direction)) {
      // update player's x and y coords 
      return "You walk to the " + direction.toString().toLowerCase() + ".";
    } else {
      return "You can't go that way.";
    }
  }
    
  // player attack method
  public String attack(Monster target) {
    // logic to calculate damage
    int damage = calculateDamage();
    target.takeDamage(damage);
    return "You attack the " + target.getName() + " for " + damage + " damage!";
  }
}
