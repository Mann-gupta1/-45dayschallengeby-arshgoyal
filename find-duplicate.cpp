class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> a;
        
        for (int i = 0; i < nums.size(); i++) {
            int count = abs(nums[i]) - 1;  
            
            if (nums[count] < 0) {
                a.push_back(count + 1); 
            } else {
                nums[count] = -nums[count];  
            }
        }
        
        return a;
    }
};
