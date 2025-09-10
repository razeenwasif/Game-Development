package com.mycompany.app;

/**
 * The main class for the game. It initializes the game, manages the game state, and handles the main game loop.
 */
public class Game {

  private UI ui;
  private Player player;
  private GameMap gameMap;
  private ChoiceHandler choiceHandler;

  /**
   * Constructs a new Game object. It initializes the UI, game map, player, and choice handler.
   */
  public Game() {
    this.ui = new UI();
    this.gameMap = new GameMap();
    this.player = new Player("Hero", 15, "Dagger");
    player.setCurrentLocation(gameMap.getStartingLocation());
    this.choiceHandler = new ChoiceHandler(this);
    ui.setStartButtonAction(e -> createGameScreen());
  }

  /**
   * Creates the main game screen. This is called when the player clicks the start button.
   */
  public void createGameScreen() {
    ui.createGameScreen(choiceHandler);
    playerSetup();
    updateUI();
  }

  /**
   * Sets up the player's initial stats on the UI.
   */
  public void playerSetup() {
    ui.hpNumLabel.setText("" + player.getHp());
    ui.weaponNameLabel.setText(player.getWeapon());
  }

  /**
   * Updates the UI with the current game state. This includes the narrative text and the choice buttons.
   */
  public void updateUI() {
    ui.narrativeTextArea.setText(player.getCurrentLocation().getDescription());
    ui.firstChoice.setText("Go North");
    ui.secondChoice.setText("Go South");
    ui.thirdChoice.setText("Go East");
    ui.fourthChoice.setText("Go West");
  }

  /**
   * The main method. It creates a new Game object to start the game.
   *
   * @param args The command line arguments.
   */
  public static void main(String[] args) {
    new Game();
  }

  /**
   * Gets the UI object.
   *
   * @return The UI object.
   */
  public UI getUi() {
    return ui;
  }

  /**
   * Gets the Player object.
   *
   * @return The Player object.
   */
  public Player getPlayer() {
    return player;
  }
}
