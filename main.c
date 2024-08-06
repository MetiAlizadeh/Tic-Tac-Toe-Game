#include <stdio.h>
#include <windows.h>
// Function declarations
void printBoard();
int isBoardFull();
int isValidMove(int move);
void playGame();
int checkWinner();

// Global board
char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
};

int main() {
    printf("Welcome to Tic Tac Toe\n");
    printBoard();
    playGame();

    char playAgain;
    printf("Game Over\n");
    printf("Want to Play Again? (y/n): ");
    getchar(); // Consume newline character left by scanf
    playAgain = getchar();

    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = '0' + (i * 3 + j + 1);
            }
        }
        main(); // Restart the game
    }

    return 0;
}

void printBoard() {
    system("cls");
    printf("\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n-------------\n");
    }
    printf("\n");
}

void playGame() {
    while (!isBoardFull()) {
        int move;
        // Player 1's move
        printf("Player 1 (X), enter your move: ");
        scanf("%d", &move);
        while (!isValidMove(move)) {
            printf("Invalid move. Try again: ");
            scanf("%d", &move);
        }
        board[(move - 1) / 3][(move - 1) % 3] = 'X';
        printBoard();
        if (checkWinner() == 1) {
            printf("Player 1 Wins!\n");
            return;
        }

        if (isBoardFull()) break;

        // Player 2's move
        printf("Player 2 (O), enter your move: ");
        scanf("%d", &move);
        while (!isValidMove(move)) {
            printf("Invalid move. Try again: ");
            scanf("%d", &move);
        }
        board[(move - 1) / 3][(move - 1) % 3] = 'O';
        printBoard();
        if (checkWinner() == 2) {
            printf("Player 2 Wins!\n");
            return;
        }
    }
    printf("It's a Draw!\n");
}

int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    return 0; // No winner yet
}

int isValidMove(int move) {
    if (move < 1 || move > 9) return 0;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

int isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}
