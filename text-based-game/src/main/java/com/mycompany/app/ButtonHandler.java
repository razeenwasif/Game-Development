package com.mycompany.app;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonHandler implements ActionListener {

  private Game game;

  public ButtonHandler(Game game) {
    this.game = game;
  }

  public void actionPerformed(ActionEvent event) {
    game.createGameScreen();
  }
}
