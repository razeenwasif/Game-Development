package com.mycompany.app;

/**
 * Represents the player in the game.
 */
public class Player {
  private String name;
  private int hp;
  private String weapon;
  private Location currentLocation;
  private Inventory inventory;

  /**
   * Constructs a new Player object with default weapon.
   *
   * @param name The name of the player.
   * @param hp The health points of the player.
   */
  public Player(String name, int hp) {
    this(name, hp, "Dagger");
  }

  /**
   * Constructs a new Player object.
   *
   * @param name The name of the player.
   * @param hp The health points of the player.
   * @param weapon The weapon of the player.
   */
  public Player(String name, int hp, String weapon) {
    this.name = name;
    this.hp = hp;
    this.weapon = weapon;
    this.inventory = new Inventory(10);
  }

  /**
   * Gets the health points of the player.
   *
   * @return The health points of the player.
   */
  public int getHp() {
    return this.hp;
  }

  /**
   * Sets the health points of the player.
   *
   * @param newHp The new health points of the player.
   */
  public void setHp(int newHp) {
    if (newHp < 0) {
      this.hp = 0;
    } else {
      this.hp = newHp;
    }
  }

  /**
   * Gets the weapon of the player.
   *
   * @return The weapon of the player.
   */
  public String getWeapon() {
    return this.weapon;
  }

  /**
   * Gets the inventory of the player.
   *
   * @return The inventory of the player.
   */
  public Inventory getInventory() {
    return this.inventory;
  }

  /**
   * Gets the current location of the player.
   *
   * @return The current location of the player.
   */
  public Location getCurrentLocation() {
    return currentLocation;
  }

  /**
   * Sets the current location of the player.
   *
   * @param currentLocation The new location of the player.
   */
  public void setCurrentLocation(Location currentLocation) {
    this.currentLocation = currentLocation;
  }

  /**
   * Moves the player in the given direction.
   *
   * @param direction The direction to move.
   * @return A message indicating the result of the move.
   */
  public String move(Direction direction) {
    Location nextLocation = currentLocation.getExit(direction);
    if (nextLocation != null) {
      setCurrentLocation(nextLocation);
      return "You walk to the " + direction.toString().toLowerCase() + ".";
    } else {
      return "You can't go that way.";
    }
  }

  /**
   * Attacks a monster.
   *
   * @param target The monster to attack.
   * @return A message indicating the result of the attack.
   */
  public String attack(Monster target) {
    // logic to calculate damage
    int damage = calculateDamage();
    target.takeDamage(damage);
    return "You attack the " + target.getName() + " for " + damage + " damage!";
  }

  /**
   * Calculates the damage dealt by the player.
   *
   * @return The amount of damage dealt.
   */
  private int calculateDamage() {
    return 10;
  }
}
