class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int flag = 0;
        
        for (int num : nums) {
            if (count == 0) {
                flag = num;
                count = 1;
            } else if (num == flag) {
                count++;
            } else {
                count--;
            }
        }
        
        return flag;
    }
};
