
package com.mycompany.app;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Handles the player's choices from the UI.
 */
public class ChoiceHandler implements ActionListener {

  private Game game;

  /**
   * Constructs a new ChoiceHandler object.
   *
   * @param game The game object.
   */
  public ChoiceHandler(Game game) {
    this.game = game;
  }

  /**
   * Handles the player's choice.
   *
   * @param e The action event.
   */
  @Override
  public void actionPerformed(ActionEvent e) {
    String choice = e.getActionCommand();

    switch (choice) {
      case "c1":
        game.getPlayer().move(Direction.NORTH);
        break;
      case "c2":
        game.getPlayer().move(Direction.SOUTH);
        break;
      case "c3":
        game.getPlayer().move(Direction.EAST);
        break;
      case "c4":
        game.getPlayer().move(Direction.WEST);
        break;
    }
    game.updateUI();
  }
}
