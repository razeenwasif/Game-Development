package com.mycompany.app;

/**
 * Represents an item in the game.
 */
public class Item {
  private String name;
  private String description;

  /**
   * Constructs a new Item object.
   *
   * @param name The name of the item.
   * @param description The description of the item.
   */
  public Item(String name, String description) {
    this.name = name;
    this.description = description;
  }

  /**
   * Gets the name of the item.
   *
   * @return The name of the item.
   */
  public String getName() {
    return name;
  }

  /**
   * Gets the description of the item.
   *
   * @return The description of the item.
   */
  public String getDescription() {
    return description;
  }
}
