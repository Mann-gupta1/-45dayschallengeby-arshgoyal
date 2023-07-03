class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[flag++] = nums[i];
            }
        }
        
        while (flag < n) {
            nums[flag++] = 0;
        }
    }
};
