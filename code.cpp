#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>> &board, int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == val)
            return false;

        if (board[row][i] == val)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isValid(board, i, j, val)) {
                        board[i][j] = val;

                        if (solveSudoku(board))
                            return true;
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int row = 9, col = 9;

    vector<vector<int>> board(row, vector<int>(col));

    cout << "Enter the elements of the board (0 for empty cells):" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board)) {
        cout << "Solved Sudoku board:" << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    } else cout << "No solution exists" << endl;

    return 0;
}
