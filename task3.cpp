#include <iostream>
#include <vector>

// Function prototypes
void displayBoard(const std::vector<std::vector<char>>& board);
bool isMoveValid(const std::vector<std::vector<char>>& board, int row, int col);
bool checkForWin(const std::vector<std::vector<char>>& board, char player);
bool checkForDraw(const std::vector<std::vector<char>>& board);
void switchPlayers(char& currentPlayer);

int main() {
    const int boardSize = 3;
    std::vector<std::vector<char>> board(boardSize, std::vector<char>(boardSize, ' '));

    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    do {
        // Display the current state of the board
        displayBoard(board);

        // Get player input
        int row, col;
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
        } while (!isMoveValid(board, row, col));

        // Update the board with the player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check for a win
        gameWon = checkForWin(board, currentPlayer);

        // Check for a draw
        gameDraw = checkForDraw(board);

        // Switch players for the next turn
        switchPlayers(currentPlayer);

    } while (!gameWon && !gameDraw);

    // Display the final state of the board
    displayBoard(board);

    // Display the result of the game
    if (gameWon) {
        switchPlayers(currentPlayer);

        std::cout << "Player " << currentPlayer << " wins! Congratulations!\n";
    } else {
        std::cout << "It's a draw! Better luck next time.\n";
    }

    return 0;
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " | ";
        }
        std::cout << "\n---------\n";
    }
    std::cout << "\n";
}

bool isMoveValid(const std::vector<std::vector<char>>& board, int row, int col) {
    // Check if the chosen cell is within the board and not already occupied
    return row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ';
}

bool checkForWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkForDraw(const std::vector<std::vector<char>>& board) {
    // Check if the board is full (no empty spaces)
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // There is an empty space, game is not a draw yet
            }
        }
    }
    return true; // All spaces are filled, game is a draw
}

void switchPlayers(char& currentPlayer) {
    // Switch between players "X" and "O"
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
