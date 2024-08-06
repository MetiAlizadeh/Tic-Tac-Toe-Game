# Tic Tac Toe Game

This is a simple command-line implementation of the classic Tic Tac Toe game written in C for Windows.

## Features

- Two-player gameplay
- Interactive command-line interface
- Board visualization after each move
- Input validation for moves
- Win detection for rows, columns, and diagonals
- Draw detection when the board is full
- Option to play multiple games

## How to Play

1. Compile the C file using a C compiler (e.g., GCC).
2. Run the executable.
3. Players take turns entering numbers 1-9 to place their mark (X or O) on the board.
4. The game ends when a player wins or the board is full (draw).
5. Choose to play again or exit after each game.

## Board Layout

The board is represented as follows:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Enter the number corresponding to the position where you want to place your mark.

## Functions

- `printBoard()`: Displays the current state of the board.
- `playGame()`: Manages the game flow, including player turns and win/draw checks.
- `checkWinner()`: Determines if there's a winner after each move.
- `isValidMove()`: Validates if a move is legal.
- `isBoardFull()`: Checks if the board is completely filled.

## Requirements

- C compiler (e.g., GCC)
- Windows operating system (uses `windows.h` for screen clearing)

## Compilation

To compile the game, use the following command:
gcc -o tictactoe tictactoe.c

## Running the Game

After compilation, run the game using:
./tictactoe
Copy
Enjoy playing Tic Tac Toe!
