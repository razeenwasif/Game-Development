package com.mycompany.app;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class Game {

  JFrame window;
  JPanel titleNamePanel, startButtonPanel, narrativeTextPanel, actionMenuPanel;
  JLabel titleNameLabel;
  JButton startButton, firstChoice, secondChoice, thirdChoice, fourthChoice;
  JTextArea narrativeTextArea;

  Container container;
  ButtonHandler buttonHandler = new ButtonHandler(this);

  Font titleFont = new Font("Times New Roman", Font.PLAIN, 58);
  Font font = new Font("Times New Roman", Font.PLAIN, 30);

  public Game() {
    // create a game window;
    window = new JFrame();
    window.setSize(800, 600);
    window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    window.getContentPane().setBackground(Color.black);
    window.setLayout(null); // disable default layout for custom layout
    container = window.getContentPane();

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
          public void mouseEntered(java.awt.event.MouseEvent evt) {
            startButton.setBackground(Color.gray);
          }

          public void mouseExited(java.awt.event.MouseEvent evt) {
            startButton.setBackground(Color.black);
          }
        });
    startButton.addActionListener(buttonHandler);

    // start button panel
    startButtonPanel = new JPanel();
    startButtonPanel.setBounds(300, 400, 200, 100);
    startButtonPanel.setBackground(Color.black);
    startButtonPanel.add(startButton);

    container.add(titleNamePanel);
    container.add(startButtonPanel);
    window.setVisible(true);
  }

  public void createGameScreen() {
    titleNamePanel.setVisible(false);
    startButtonPanel.setVisible(false);

    // story text panel
    narrativeTextPanel = new JPanel();
    narrativeTextPanel.setBounds(100, 100, 600, 250);
    narrativeTextPanel.setBackground(Color.blue);

    container.add(narrativeTextPanel);

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
    actionMenuPanel.setBackground(Color.red);
    actionMenuPanel.setLayout(new GridLayout(4, 1));

    container.add(actionMenuPanel);

    firstChoice = new JButton("Choice 1");
    firstChoice.setBackground(Color.black);
    firstChoice.setForeground(Color.white);
    firstChoice.setFont(font);
    actionMenuPanel.add(firstChoice);

    secondChoice = new JButton("Choice 2");
    secondChoice.setBackground(Color.black);
    secondChoice.setForeground(Color.white);
    secondChoice.setFont(font);
    actionMenuPanel.add(secondChoice);

    thirdChoice = new JButton("Choice 3");
    thirdChoice.setBackground(Color.black);
    thirdChoice.setForeground(Color.white);
    thirdChoice.setFont(font);
    actionMenuPanel.add(thirdChoice);

    fourthChoice = new JButton("Choice 4");
    fourthChoice.setBackground(Color.black);
    fourthChoice.setForeground(Color.white);
    fourthChoice.setFont(font);
    actionMenuPanel.add(fourthChoice);
  }

  public static void main(String[] args) {
    new Game(); // instantiate a new Game object
  }
}
