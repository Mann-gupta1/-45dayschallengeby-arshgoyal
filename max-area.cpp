class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
                int i = 0, j = n - 1;

        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            max_area = max(max_area, area);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max_area;
    }
};
