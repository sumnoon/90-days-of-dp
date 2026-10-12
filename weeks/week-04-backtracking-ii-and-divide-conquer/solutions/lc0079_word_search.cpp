#include <chrono>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<bool>> visited;
    int fx[4] = {0, 0, 1, -1};
    int fy[4] = {1, -1, 0, 0};
    bool valid(int x, int y, int n, int m) { return (x >= 0 && x < n && y >= 0 && y < m); }
    bool backtrack(int i, int j, int n, int m, vector<vector<char>>& board, const string& word,
                   int idx) {
        if (word[idx] != board[i][j]) {
            return false;
        }
        if (idx == word.length() - 1) {
            return true;
        }

        board[i][j] = '#';

        for (int k = 0; k < 4; ++k) {
            int tx = fx[k] + i;
            int ty = fy[k] + j;
            if (valid(tx, ty, n, m)) {
                if (backtrack(tx, ty, n, m, board, word, idx + 1)) return true;
            }
        }

        board[i][j] = word[idx];

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (backtrack(i, j, n, m, board, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

// --- local harness (LeetCode supplies these) ---

using Board = vector<vector<char>>;

Board make(const vector<string>& rows) {
    Board b;
    for (auto& r : rows) b.push_back(vector<char>(r.begin(), r.end()));
    return b;
}

int main() {
    vector<string> ex = {"ABCE", "SFCS", "ADEE"};
    struct Case { vector<string> board; string word; bool want; };
    Case cases[] = {
        {ex, "ABCCED", true},          // LeetCode example 1
        {ex, "SEE", true},             // LeetCode example 2
        {ex, "ABCB", false},           // LeetCode example 3: would reuse the B
        {{"A"}, "A", true},
        {{"A"}, "B", false},
        {{"AB"}, "ABA", false},        // needs the A twice
        {{"AB", "BA"}, "ABAB", true},  // around the square
        {{"CAA", "AAA", "BCD"}, "AAB", true},
        {{"ABCE", "SFES", "ADEE"}, "ABCESEEEFS", true},   // a long snake (LeetCode test)
        {ex, "ABCESEEEFS", false},     // the same word on example 1: no third E in reach
    };
    int failed = 0;
    for (auto& [rows, word, want] : cases) {
        Board b = make(rows);
        bool got = Solution().exist(b, word);   // a fresh object per call
        bool ok = got == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << word << " -> " << boolalpha << got;
        if (b != make(rows)) cout << "   (board left modified)";
        cout << endl;
    }

    // Worst case at LeetCode's limits: 6 x 6 of 'A', a 15-letter word that ends in 'B'.
    Board big = make(vector<string>(6, "AAAAAA"));
    auto t0 = chrono::steady_clock::now();
    bool r = Solution().exist(big, "AAAAAAAAAAAAAAB");
    auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
    bool ok = !r && big == make(vector<string>(6, "AAAAAA"));
    if (!ok) ++failed;
    cout << (ok ? "ok   " : "FAIL ") << "6x6 all-A, no B: false in " << ms << " ms, board restored" << endl;

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
