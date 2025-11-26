#include <bits/stdc++.h>
using namespace std;

bool isSafeQueen(const vector<string> &board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void solveNQUtil(int row, int n, vector<string> &board, vector<vector<string>> &ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafeQueen(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQUtil(row + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solveNQUtil(0, n, board, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter N for N-Queens: ";
    cin >> n;
    vector<vector<string>> solutions = solveNQueens(n);
    cout << "Number of solutions: " << solutions.size() << "\n";
    for (auto &board : solutions) {
        cout << "Solution:\n";
        for (auto &row : board) cout << row << "\n";
        cout << "\n";
    }
    return 0;
}
