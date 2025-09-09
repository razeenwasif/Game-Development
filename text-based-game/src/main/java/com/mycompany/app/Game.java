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
    JPanel titleNamePanel, startButtonPanel;
    JLabel titleNameLabel;
    JButton startButton;
    Container container;
    Font titleFont = new Font("Times New Roman", Font.PLAIN, 58);
    
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
      
      // title pane 
      titleNamePanel = new JPanel();
      titleNamePanel.setBounds(100, 100, 600, 150);
      titleNamePanel.setBackground(Color.blue);
      titleNamePanel.add(titleNameLabel);

      // start button 
      startButton = new JButton("START");
      startButton.setForeground(Color.black);

      startButtonPanel = new JPanel();
      startButtonPanel.setBounds(300, 400, 200, 100);
      startButtonPanel.setBackground(Color.blue);
      startButtonPanel.add(startButton);

      container.add(titleNamePanel);
      container.add(startButtonPanel);
      window.setVisible(true);
    }

    public static void main( String[] args ) {
      new Game(); // instantiate a new Game object
    }

}
