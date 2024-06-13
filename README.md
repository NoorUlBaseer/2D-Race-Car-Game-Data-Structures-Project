**2D Race Car Game
**Introduction:
Welcome to the 2D Race Car Game! It is a grid-based racing game implemented using C++ and various data structures where players navigate a car from a starting point to an end point, overcoming obstacles and collecting power-ups along the way.
Features:
1. Manual and Automatic Modes:
o Manual Mode: Players control the car using keyboard inputs.
o Automatic Mode: The car automatically navigates the grid using Dijkstra's algorithm to find the shortest path from start to end.
2. Leaderboard:
o The game maintains a leaderboard to keep track of player scores, which are stored in a CSV file and updated after each game.
3. Graph Implementation:
o The game grid is represented as a graph with vertices and edges. Each cell in the grid corresponds to a vertex.
4. Obstacles and Power-ups:
o Randomly placed obstacles and power-ups add an element of challenge and strategy to the game.
Controls:
* W or Up Arrow: Accelerate
* S or Down Arrow: Brake and reverse
* A or Left Arrow: Turn left
* D or Right Arrow: Turn right
* ESC: Exit the game
Game Elements:
* Car: Represented by 'C'
* Start Point: Represented by 'S'
* Finish Point: Represented by 'E'
* Power-Ups: Represented by '+'
* Obstacles: Represented by '#'
How to Play:
1. Manual Mode:
o Select manual mode from the main menu.
o Enter your name (new or existing).
o Use the control keys to navigate the car from the start point to the finish point.
o Avoid obstacles and collect power-ups to improve your score.
2. Automatic Mode:
o Select automatic mode from the main menu.
o Enter the start and end coordinates for the car.
o Watch as the car navigates the grid using the shortest path algorithm.
3. Leaderboard:
o View the current leaderboard to see the top scores and players.
Code Structure:
* Project.cpp: Contains the main logic for the game, including the game loop and menu.
* Graph: Represents the game grid using vertices and edges.
* BST: Binary Search Tree implementation for maintaining the leaderboard.
* Queue: Queue implementation for handling obstacles and power-ups.
* Header.h: Header file containing class declarations and necessary imports.
Dependencies:
* Libraries:
o <iostream>: For input and output operations.
o <string>: For handling strings.
o <windows.h>: For the sleep function.
o <conio.h>: For _getch() function.
o <iomanip>: For formatting output.
o <fstream>: For file handling.
* Color Definitions:
o Macros for different colors used in the console output (e.g., RED, GREEN, etc.).
Setup and Execution:
1. Compile the Code:
o Use a C++ compiler to compile the source code.
2. Run the Executable:
o Execute the compiled program to start the game.

