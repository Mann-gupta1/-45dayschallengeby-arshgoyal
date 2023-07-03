class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count = 1;
        while (count != 0) {
            count = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] > nums[i]) {
                    int temp = nums[i - 1];
                    nums[i - 1] = nums[i];
                    nums[i] = temp;
                    count++;
                }
            }
        }
    }
};
