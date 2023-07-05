class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int up = 0;
        int down = rows - 1;
        int pre = 0;
        int next = cols - 1;
        
        while (up <= down && pre <= next) {
            for (int col = pre; col <= next; col++) {
                result.push_back(matrix[up][col]);
            }
            up++;
            
            
            for (int row = up; row <= down; row++) {
                result.push_back(matrix[row][next]);
            }
            next--;
            
            if (up <= down) {
                
                for (int col = next; col >= pre; col--) {
                    result.push_back(matrix[down][col]);
                }
                down--;
            }
            
            if (pre <= next) {
                for (int row = down; row >= up; row--) {
                    result.push_back(matrix[row][pre]);
                }
                pre++;
            }
        }
        
        return result;
    }
};
