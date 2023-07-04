class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;  
        int count = 0;  
        int sum = 0;  
        remainderCount[0] = 1;
        
        for (int num : nums) {
            sum += num;  
            int remainder = ((sum % k) + k) % k;
            
            if (remainderCount.count(remainder)) {
                count += remainderCount[remainder];     }
            
            remainderCount[remainder]++;  
        }
        
        return count;
    }
};
