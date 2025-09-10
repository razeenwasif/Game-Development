
package com.mycompany.app;

/**
 * Represents the game map. It creates and manages all the locations in the game.
 */
public class GameMap {

  private Location startingLocation;

  /**
   * Constructs a new GameMap object. It creates the game map.
   */
  public GameMap() {
    createMap();
  }

  /**
   * Creates the game map by creating all the locations and linking them together.
   */
  private void createMap() {
    Location townSquare = new Location("Town Square", "You are in the town square. You see a fountain.");
    Location north = new Location("North", "You are north of the town square.");
    Location south = new Location("South", "You are south of the town square.");
    Location east = new Location("East", "You are east of the town square.");
    Location west = new Location("West", "You are west of the town square.");

    townSquare.addExit(Direction.NORTH, north);
    townSquare.addExit(Direction.SOUTH, south);
    townSquare.addExit(Direction.EAST, east);
    townSquare.addExit(Direction.WEST, west);

    north.addExit(Direction.SOUTH, townSquare);
    south.addExit(Direction.NORTH, townSquare);
    east.addExit(Direction.WEST, townSquare);
    west.addExit(Direction.EAST, townSquare);

    this.startingLocation = townSquare;
  }

  /**
   * Gets the starting location of the game.
   *
   * @return The starting location.
   */
  public Location getStartingLocation() {
    return startingLocation;
  }
}
