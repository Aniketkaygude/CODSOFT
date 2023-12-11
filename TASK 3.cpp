#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char player, int row, int col);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    const int boardSize = 3;
    vector<vector<char>> board(boardSize, vector<char>(boardSize, ' '));

    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    do {
        // Display the current state of the board
        displayBoard(board);

        // Get the current player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Make the move and check for validity
        if (makeMove(board, currentPlayer, row, col)) {
            // Check for a win
            gameWon = checkWin(board, currentPlayer);

            // Check for a draw
            gameDraw = checkDraw(board);

            // Switch to the next player
            switchPlayer(currentPlayer);
        } else {
            cout << "Invalid move. Try again." << endl;
        }

    } while (!gameWon && !gameDraw);

    // Display the final state of the board
    displayBoard(board);

    // Display the result of the game
    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < board.size(); ++i) {
        cout << i << " ";
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
            if (j < board[i].size() - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < board.size() - 1) {
            cout << "  -----" << endl;
        }
    }
    cout << endl;
}

bool makeMove(vector<vector<char>>& board, char player, int row, int col) {
    // Check if the chosen cell is empty
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } else {
        return false; // Cell is already occupied
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    // Check if any cell is still empty
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') {
                return false; // Game is not a draw
            }
        }
    }
    return true; // All cells are filled, game is a draw
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}