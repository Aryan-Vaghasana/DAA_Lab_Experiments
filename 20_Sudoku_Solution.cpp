#include <bits/stdc++.h>
using namespace std;

bool isSafeSudoku(vector<vector<int>> &grid, int row, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    int sr = row - row % 3;
    int sc = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[sr + i][sc + j] == num) return false;
    return true;
}

bool solveSudoku(vector<vector<int>> &grid) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (grid[r][c] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafeSudoku(grid, r, c, num)) {
                        grid[r][c] = num;
                        if (solveSudoku(grid)) return true;
                        grid[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> grid(9, vector<int>(9));
    cout << "Enter 9x9 Sudoku (0 for empty):\n";
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];
    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << grid[i][j] << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution exists\n";
    }
    return 0;
}
