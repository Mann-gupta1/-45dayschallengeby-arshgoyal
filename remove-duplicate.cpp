class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }
        nums.clear();  
        for (int num : set) {
            nums.push_back(num);
        }
        sort(nums.begin(),nums.end());
        
        return nums.size();
    }
};
