class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
private:
    int mergeSort(vector<int>& nums, int pre, int next) {
        if (pre >= next) {
            return 0;
        }
        
        int flag = pre + (next - pre) / 2;
        int count = mergeSort(nums, pre, flag) + mergeSort(nums, flag + 1, next);
        
        int i = pre;
        int j = flag + 1;
        
        while (i <= flag && j <= next) {
            if ((long long)nums[i] > 2LL * nums[j]) {
                count += flag - i + 1;  
                j++;
            } else {
                i++;
            }
        }
        
        merge(nums, pre, flag, next);
        
        return count;
    }
    
    void merge(vector<int>& nums, int pre, int flag, int next) {
        vector<int> a(next - pre + 1);
        int i = pre;
        int j = flag + 1;
        int k = 0;
        
        while (i <= flag && j <= next) {
            if (nums[i] <= nums[j]) {
                a[k++] = nums[i++];
            } else {
                a[k++] = nums[j++];
            }
        }
        
        while (i <= flag) {
            a[k++] = nums[i++];
        }
        
        while (j <= next) {
            a[k++] = nums[j++];
        }
        
        for (int p = 0; p < a.size(); p++) {
            nums[pre + p] = a[p];
        }
    }
};
