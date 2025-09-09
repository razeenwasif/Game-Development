package com.mycompany.app;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Game {
    
    JFrame window;
    JPanel titleNamePanel, startButtonPanel, narrativeTextPanel;
  JLabel titleNameLabel;
    JButton startButton;
    Container container;
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
      startButton.addMouseListener(new java.awt.event.MouseAdapter() {
          public void mouseEntered(java.awt.event.MouseEvent evt) {
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

      container.add(titleNamePanel);
      container.add(startButtonPanel);
      window.setVisible(true);
    }

    public void createGameScreen() {

    }

    public static void main( String[] args ) {
      new Game(); // instantiate a new Game object
    }

}
