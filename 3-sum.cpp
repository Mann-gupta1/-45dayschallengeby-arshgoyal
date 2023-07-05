class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> tri;
        int n = nums.size();
        
        if (n < 3) {
            return tri;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int pre = i + 1;
            int next = n - 1;
            
            while (pre < next) {
                int sum = nums[i] + nums[pre] + nums[next];
                
                if (sum == 0) {
                    tri.push_back({nums[i], nums[pre], nums[next]});
                    
                    while (pre < next && nums[pre] == nums[pre + 1]) {
                        pre++;
                    }
                    
                    while (pre < next && nums[next] == nums[next - 1]) {
                        next--;
                    }
                    
                    pre++;
                    next--;
                } else if (sum < 0) {
                    pre++;
                } else {
                    next--;
                }
            }
        }
        
        return tri;
    }
};
