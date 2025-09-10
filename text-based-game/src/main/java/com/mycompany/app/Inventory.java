package com.mycompany.app;

import java.util.ArrayList;
import java.util.List;

/**
 * Represents the player's inventory.
 */
public class Inventory {
  private List<Item> items;
  private int capacity;

  /**
   * Constructs a new Inventory object.
   *
   * @param capacity The maximum number of items that the inventory can hold.
   */
  public Inventory(int capacity) {
    this.items = new ArrayList<>();
    this.capacity = capacity;
  }

  /**
   * Adds an item to the inventory.
   *
   * @param item The item to add.
   * @return True if the item was added successfully, false otherwise.
   */
  public boolean addItem(Item item) {
    if (items.size() < capacity) {
      items.add(item);
      return true;
    } else {
      return false; // full inventory 
    }
  }

  /**
   * Removes an item from the inventory.
   *
   * @param item The item to remove.
   */
  public void removeItem(Item item) {
    items.remove(item);
  }

  /**
   * Gets the list of items in the inventory.
   *
   * @return The list of items.
   */
  public List<Item> getItems() {
    return items;
  }
}
