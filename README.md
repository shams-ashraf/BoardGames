BoardGames
A C++ implementation of multiple board games including 3x3 Tic-Tac-Toe, 5x5 Tic-Tac-Toe, Pyramid Tic-Tac-Toe, and Connect Four. The project supports human players and a random computer player, with a unified game management system for running different game modes.
Overview
This project provides a modular implementation of four board games using object-oriented C++:

3x3 Tic-Tac-Toe: Classic 3x3 grid where players alternate placing 'X' or 'O' to get three in a row, column, or diagonal.
5x5 Tic-Tac-Toe: A 5x5 grid variant where players aim to get three in a row, with a scoring system for multiple winning lines.
Pyramid Tic-Tac-Toe: A triangular board (1 cell on row 0, 3 on row 1, 5 on row 2) with specific winning conditions.
Connect Four: A 6x7 grid where players drop 'X' or 'O' to connect four in a row, column, or diagonal.

The project uses a base Board class with derived classes for each game, a Player class for human players, a RandomPlayer class for computer moves, and a GameManager to handle game flow.
Features

Multiple Games:
3x3 Tic-Tac-Toe: Standard rules with win/draw detection.
5x5 Tic-Tac-Toe: Counts three-in-a-row lines for 'X' and 'O', declares winner based on score.
Pyramid Tic-Tac-Toe: Unique board layout with specific winning patterns (e.g., diagonals like (0,0)-(1,1)-(2,2)).
Connect Four: Gravity-based piece placement with four-in-a-row win condition.


Player Types:
Human players input moves via coordinates.
Random computer player generates valid moves automatically.


Game Management: Unified GameManager class to run any game, handling player turns, board updates, and win/draw conditions.
Input Validation: Ensures valid moves (within bounds, unoccupied cells) with error messages for invalid inputs.

Requirements

Operating System: Any OS with a C++ compiler (e.g., Windows, Linux, macOS).
Compiler: C++ compiler supporting C++11 or later (e.g., g++, MSVC).
Libraries: Standard C++ libraries (iostream, random, iomanip, algorithm).

Build Instructions

Clone the repository:git clone https://github.com/shams-ashraf/BoardGames.git


Compile the project:g++ -std=c++11 *.cpp -o BoardGames

Or, if using an IDE like Visual Studio:
Create a new project.
Add all .cpp and .hpp files to the project.
Build in Release or Debug mode.


Run the executable:./BoardGames



Usage

Run the program and choose a player mode:
Press 1 to play against a random computer player (uses 'O').
Press any other key to play against another human player.


Select a game:
1: Pyramid Tic-Tac-Toe
2: Connect Four
3: 5x5 Tic-Tac-Toe
4: 3x3 Tic-Tac-Toe


Follow prompts to enter moves (x, y coordinates) for human players. The random player moves automatically.
The game displays the board after each move and announces the winner or a draw.

Example Gameplay
Welcome to FCAI tic_tac_toe Game. :)
Press 1 if you want to play with computer: 1
Welcome player 1
Please enter your name: Alice
My names is Random Computer Player
choose game you want to play
1.for pyramid tic tac toe
2.for four in a row
3.for 5x5 tic tac toe
4.for x_o
4

| (0,0)  | (0,1)  | (0,2)  |
-----------------------------
| (1,0)  | (1,1)  | (1,2)  |
-----------------------------
| (2,0)  | (2,1)  | (2,2)  |
-----------------------------

Please enter your move x and y (0 to 2) separated by spaces: 1 1

(Continues until a win or draw.)
File Structure

BoardGame_Classes.hpp: Header file defining base and derived classes (Board, Player, RandomPlayer, GameManager, game-specific boards).
GameManager.cpp: Implements the game loop and player management.
Player.cpp: Implements human player functionality (name input, move selection).
RandomPlayer.cpp: Implements random computer player moves.
X_O_Board.cpp: Implements 3x3 Tic-Tac-Toe board logic.
connect_four.cpp: Implements Connect Four board logic.
tic_tac_toe_5x5.cpp: Implements 5x5 Tic-Tac-Toe board logic with scoring.
pyramic_tic_tac_toe.cpp: Implements Pyramid Tic-Tac-Toe board logic.
main.cpp: Entry point for selecting and running a game.
.gitignore: Ignores build artifacts (e.g., .exe, .obj) and IDE-specific files.

Notes

The 5x5 Tic-Tac-Toe game counts three-in-a-row lines but returns false for is_winner(), relying on display_board() to announce the winner based on scores (count_x vs. count_o).
Pyramid Tic-Tac-Toe has a unique board layout (1-3-5 cells) with specific valid moves (e.g., row 0 only allows y=0).
Connect Four implements gravity (pieces fall to the lowest empty cell in a column).
The random player may not always make optimal moves, as it selects coordinates randomly within board dimensions.
Invalid moves (e.g., out-of-bounds or occupied cells) prompt the user to retry with an error message.
