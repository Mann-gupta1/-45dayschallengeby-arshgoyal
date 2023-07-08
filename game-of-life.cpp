#include <vector>

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(); 
        int n = board[0].size(); 

        vector<vector<int>> v(board);

        vector<int> a = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> b = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0; 

                
                for (int k = 0; k < 8; ++k) {
                    int x = i + a[k];
                    int y = j + b[k];

                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1) {
                        ++count;
                    }
                }

                if (board[i][j] == 1 && (count < 2 || count > 3)) {

                    v[i][j] = 0; 
                } else if (board[i][j] == 0 && count == 3) {
                    
                    v[i][j] = 1; 
                }
            }
        }

        board = v;
    }
};
