// Week 4 Saturday: LC 51 N-Queens (sets for columns and both diagonals)
#include <algorithm>
#include <chrono>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> ans;
    vector<bool> col_used, main_diag_used, anti_diag_used;
    bool valid(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
    void backtrack(int row, int n, vector<string>& board) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); ++col) {
            int main_d = row - col + n - 1;
            int anti_d = row + col;

            if (col_used[col] || main_diag_used[main_d] || anti_diag_used[anti_d]) continue;

            board[row][col] = 'Q';
            col_used[col] = anti_diag_used[anti_d] = main_diag_used[main_d] = true;

            backtrack(row + 1, n, board);

            board[row][col] = '.';
            col_used[col] = anti_diag_used[anti_d] = main_diag_used[main_d] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        col_used.assign(n, false);
        main_diag_used.assign(2 * n - 1, false);
        anti_diag_used.assign(2 * n - 1, false);

        backtrack(0, n, board);
        return ans;
    }
};


// Independent check: exactly one queen per row, no two sharing a column or diagonal.
bool legal(const vector<string>& b, int n) {
    if ((int)b.size() != n) return false;
    vector<int> q;
    for (auto& row : b) {
        if ((int)row.size() != n || count(row.begin(), row.end(), 'Q') != 1 ||
            count(row.begin(), row.end(), '.') != n - 1) return false;
        q.push_back(row.find('Q'));
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (q[i] == q[j] || abs(q[i] - q[j]) == j - i) return false;
    return true;
}

int main() {
    const size_t known[] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352};   // OEIS A000170
    int failed = 0;
    for (int n = 1; n <= 9; ++n) {                                 // LeetCode: 1 <= n <= 9
        auto t0 = chrono::steady_clock::now();
        auto got = Solution().solveNQueens(n);                     // a fresh object per call
        auto us = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - t0).count();
        set<vector<string>> distinct(got.begin(), got.end());
        bool ok = got.size() == known[n] && distinct.size() == got.size();
        for (auto& b : got) ok = ok && legal(b, n);
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "n = " << n << ": " << got.size() << " boards, " << us << " us" << endl;
        if (n == 4) for (auto& b : got) { for (auto& r : b) cout << "     " << r << endl; cout << endl; }
    }
    cout << (failed ? "some FAILED" : "n = 1..9: every count matches, every board legal and distinct") << endl;
    return failed != 0;
}
