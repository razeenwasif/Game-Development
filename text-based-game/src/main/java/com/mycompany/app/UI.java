
package com.mycompany.app;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

/**
 * The UI class handles all the user interface elements of the game.
 * It creates the game window, panels, buttons, and text areas.
 */
public class UI {

  JFrame window;
  JPanel titleNamePanel, startButtonPanel, narrativeTextPanel, actionMenuPanel;
  JPanel playerStatusPanel;
  JLabel titleNameLabel, hpLabel, hpNumLabel, weaponLabel, weaponNameLabel;
  JButton startButton, firstChoice, secondChoice, thirdChoice, fourthChoice;
  JTextArea narrativeTextArea;

  Font titleFont = new Font("Times New Roman", Font.PLAIN, 48);
  Font font = new Font("Times New Roman", Font.PLAIN, 30);

  /**
   * Constructs a new UI object.
   * It initializes the main game window and the title screen.
   */
  public UI() {
    // create a game window;
    window = new JFrame();
    window.setSize(800, 600);
    window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    window.getContentPane().setBackground(Color.black);
    window.setLayout(null); // disable default layout for custom layout

    // title String
    titleNameLabel = new JLabel("Name of game goes here");
    titleNameLabel.setForeground(Color.white);
    titleNameLabel.setFont(titleFont);

    // title panel
    titleNamePanel = new JPanel();
    titleNamePanel.setBounds(100, 100, 600, 150);
    titleNamePanel.setBackground(Color.black);
    titleNamePanel.add(titleNameLabel);

    // start button
    startButton = new JButton("START");
    startButton.setForeground(Color.white);
    startButton.setBackground(Color.black);
    startButton.setOpaque(true);
    startButton.setBorderPainted(false);
    startButton.setFont(font);
    startButton.addMouseListener(
        new java.awt.event.MouseAdapter() {
          public void mouseEnteblack(java.awt.event.MouseEvent evt) {
            startButton.setBackground(Color.gray);
          }

          public void mouseExited(java.awt.event.MouseEvent evt) {
            startButton.setBackground(Color.black);
          }
        });

    // start button panel
    startButtonPanel = new JPanel();
    startButtonPanel.setBounds(300, 400, 200, 100);
    startButtonPanel.setBackground(Color.black);
    startButtonPanel.add(startButton);

    Container container = window.getContentPane();
    container.add(titleNamePanel);
    container.add(startButtonPanel);
    window.setVisible(true);
  }

  /**
   * Creates the main game screen.
   * This method is called after the player clicks the start button.
   * It sets up the player status panel, narrative text area, and action menu.
   *
   * @param buttonHandler The action listener for the choice buttons.
   */
  public void createGameScreen(ActionListener buttonHandler) {
    titleNamePanel.setVisible(false);
    startButtonPanel.setVisible(false);

    // player status panel
    playerStatusPanel = new JPanel();
    playerStatusPanel.setBounds(100, 15, 600, 50);
    playerStatusPanel.setBackground(Color.black);
    playerStatusPanel.setLayout(new GridLayout(1, 4));

    // Player HP Label
    hpLabel = new JLabel("HP:");
    hpLabel.setFont(font);
    hpLabel.setForeground(Color.white);
    playerStatusPanel.add(hpLabel);
    // Player HP Number Label
    hpNumLabel = new JLabel();
    hpNumLabel.setFont(font);
    hpNumLabel.setForeground(Color.white);
    playerStatusPanel.add(hpNumLabel);

    // Weapon Label
    weaponLabel = new JLabel("Weapon:");
    weaponLabel.setFont(font);
    weaponLabel.setForeground(Color.white);
    playerStatusPanel.add(weaponLabel);
    // Weapon Number Label
    weaponNameLabel = new JLabel();
    weaponNameLabel.setFont(font);
    weaponNameLabel.setForeground(Color.white);
    playerStatusPanel.add(weaponNameLabel);

    // story text panel
    narrativeTextPanel = new JPanel();
    narrativeTextPanel.setBounds(100, 100, 600, 250);
    narrativeTextPanel.setBackground(Color.black);

    narrativeTextArea = new JTextArea("Text Area");
    narrativeTextArea.setBounds(100, 100, 600, 250);
    narrativeTextArea.setBackground(Color.black);
    narrativeTextArea.setForeground(Color.white);
    narrativeTextArea.setFont(font);
    narrativeTextArea.setLineWrap(true);

    narrativeTextPanel.add(narrativeTextArea);

    // action menu panel
    actionMenuPanel = new JPanel();
    actionMenuPanel.setBounds(250, 350, 300, 150);
    actionMenuPanel.setBackground(Color.black);
    actionMenuPanel.setLayout(new GridLayout(4, 1));

    firstChoice = new JButton("Choice 1");
    firstChoice.setBackground(Color.black);
    firstChoice.setForeground(Color.white);
    firstChoice.setFont(font);
    firstChoice.addActionListener(buttonHandler);
    firstChoice.setActionCommand("c1");
    actionMenuPanel.add(firstChoice);

    secondChoice = new JButton("Choice 2");
    secondChoice.setBackground(Color.black);
    secondChoice.setForeground(Color.white);
    secondChoice.setFont(font);
    secondChoice.addActionListener(buttonHandler);
    secondChoice.setActionCommand("c2");
    actionMenuPanel.add(secondChoice);

    thirdChoice = new JButton("Choice 3");
    thirdChoice.setBackground(Color.black);
    thirdChoice.setForeground(Color.white);
    thirdChoice.setFont(font);
    thirdChoice.addActionListener(buttonHandler);
    thirdChoice.setActionCommand("c3");
    actionMenuPanel.add(thirdChoice);

    fourthChoice = new JButton("Choice 4");
    fourthChoice.setBackground(Color.black);
    fourthChoice.setForeground(Color.white);
    fourthChoice.setFont(font);
    fourthChoice.addActionListener(buttonHandler);
    fourthChoice.setActionCommand("c4");
    actionMenuPanel.add(fourthChoice);

    Container container = window.getContentPane();
    container.add(playerStatusPanel);
    container.add(narrativeTextPanel);
    container.add(actionMenuPanel);
    
    playerStatusPanel.setVisible(true);
    narrativeTextPanel.setVisible(true);
    actionMenuPanel.setVisible(true);
  }

  /**
   * Sets the action listener for the start button.
   *
   * @param listener The action listener to be set.
   */
  public void setStartButtonAction(ActionListener listener) {
    startButton.addActionListener(listener);
  }
}
