package com.mycompany.app;

import java.util.ArrayList;
import java.util.List;

public class Inventory {
  private List<Item> items;
  private int capacity;

  public Inventory(int capacity) {
    this.items = new ArrayList<>();
    this.capacity = capacity;
  }

  public boolean addItem(Item item) {
    if (items.size() < capacity) {
      items.add(item);
      return true;
    } else {
      return false; // full inventory 
    }
  }

  public void removeItem(Item item) {
    items.remove(item);
  }
}
