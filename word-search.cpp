class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }

        rows = board.size();
        cols = board[0].size();
        a.resize(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    int rows;
    int cols;
    vector<vector<bool>> a;

    bool backtrack(vector<vector<char>>& board, const string& word, int index, int row, int col) {
        if (index == word.length()) {
            return true;
        }

        if (row < 0 || row >= rows || col < 0 || col >= cols || a[row][col] || board[row][col] != word[index]) {
            return false;
        }

        a[row][col] = true;

        if (backtrack(board, word, index + 1, row + 1, col) ||
            backtrack(board, word, index + 1, row - 1, col) ||
            backtrack(board, word, index + 1, row, col + 1) ||
            backtrack(board, word, index + 1, row, col - 1)) {
            return true;
        }

        a[row][col] = false;

        return false;
    }
};
