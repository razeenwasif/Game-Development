Markdown

# Space Invaders AI with NEAT

This project implements a Space Invaders clone in C++ using Raylib and trains an AI agent to play the game using the NeuroEvolution of Augmenting Topologies (NEAT) algorithm.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Game Controls](#game-controls)
- [Project Structure](#project-structure)
- [Dependencies](#dependencies)
- [NEAT Implementation](#neat-implementation)
- [Genome Representation](#genome-representation)
- [Fitness Function](#fitness-function)

## Features

- **Classic Space Invaders Gameplay:** Implements the core mechanics of Space Invaders, including player movement, shooting, alien movement, and collisions.
- **NEAT AI Training:**  Uses the NEAT algorithm to evolve neural networks that control the player ship.
- **Raylib Graphics:** Leverages Raylib for rendering the game and visualizations.
- **Configurable Parameters:** Allows customization of various game parameters, such as alien speed, shooting frequency, and population size.
- **Save/Load Functionality:** Enables saving and loading of evolved genomes.

## Installation

1. **Clone the repository:**
2. Install Raylib: Follow the instructions for installing Raylib on your system: https://www.raylib.com/
3. Run the project using F5

## Game Controls
Player controls:
- left arrow key / A: move spaceship left
- right arrow key / D: move spaceship right
- spacebar: shoot laser
AI:
- press the i key to switch to AI mode and watch the AI play

## Project Structure
Space-Invaders/
├── src/
│   ├── genome/
│   ├── neat/
│   ├── alien.cpp
│   ├── main.cpp       # Entry point
│   ├── spaceship.cpp   
│   ├── spaceship.hpp     
│   ├── laser.hpp      
│   ├── laser.cpp
│   ├── game.hpp       # main game logic
│   ├── game.cpp
│   
├── include/
│   ├── ...            # Header files
├── lib/               
├── assets/            # Game assets (images, fonts, sounds)
├── main.code-workspace     
├── Makefile           # Makefile (if using Make)
└── README.md          # This file

## Dependencies

    C++
    Raylib

## NEAT Implementation

This project uses the NEAT algorithm to evolve neural networks that control the player ship. The NEAT implementation handles the creation, mutation, and crossover of neural network genomes.
Genome Representation

Describe how the neural network genome is represented in your implementation.  For instance:

    Input Nodes: What are the inputs to the neural network? (e.g., distance to closest alien, number of aliens alive, player's x-position).
    Output Nodes: What are the outputs of the neural network? (e.g., move left, move right, shoot).
    Connections: How are the connections between nodes represented? Are they weighted?

Fitness Function

Explain how the fitness of a genome is evaluated.  What criteria determine a successful genome?  For example:

    Survival Time: How long does the player ship survive?
    Score: How many aliens are destroyed?
    Combination: A combination of survival time and score.