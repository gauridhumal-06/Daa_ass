#include <iostream>
using namespace std;

#define N 4 // Number of queens and size of the chessboard

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // If no conflicts are found, the placement is valid
    return true;
}

bool solveNQueensUtil(int board[N][N], int row) {
    if (row == N) {
        // All queens are placed, print the solution
        printBoard(board);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            res = solveNQueensUtil(board, row + 1) || res;
            board[row][col] = 0; // Backtrack and try a different column
        }
    }

    return res;
}

void solveNQueens() {
    int board[N][N] = {0}; // Initialize the chessboard grid with all cells set to 0

    if (!solveNQueensUtil(board, 0)) {
        cout << "No solution found." << endl;
    }
}

int main() {
    solveNQueens();

    return 0;
}
