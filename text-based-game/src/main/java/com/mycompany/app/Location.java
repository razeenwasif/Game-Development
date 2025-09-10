
package com.mycompany.app;

import java.util.HashMap;
import java.util.Map;

/**
 * Represents a location in the game world.
 */
public class Location {

  private String name;
  private String description;
  private Map<Direction, Location> exits;

  /**
   * Constructs a new Location object.
   *
   * @param name The name of the location.
   * @param description The description of the location.
   */
  public Location(String name, String description) {
    this.name = name;
    this.description = description;
    this.exits = new HashMap<>();
  }

  /**
   * Adds an exit to the location.
   *
   * @param direction The direction of the exit.
   * @param location The location that the exit leads to.
   */
  public void addExit(Direction direction, Location location) {
    exits.put(direction, location);
  }

  /**
   * Gets the exit in the given direction.
   *
   * @param direction The direction of the exit.
   * @return The location that the exit leads to, or null if there is no exit in that direction.
   */
  public Location getExit(Direction direction) {
    return exits.get(direction);
  }

  /**
   * Gets the name of the location.
   *
   * @return The name of the location.
   */
  public String getName() {
    return name;
  }

  /**
   * Gets the description of the location.
   *
   * @return The description of the location.
   */
  public String getDescription() {
    return description;
  }
}
