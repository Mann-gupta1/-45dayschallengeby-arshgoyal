class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> qu;
        int n = nums.size();

        if (n < 4) {
            return qu;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long long pre = j + 1;
                long long next = n - 1;

                while (pre<next) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[pre] + nums[next];

                    if (sum == target) {
                        qu.push_back({nums[i], nums[j], nums[pre], nums[next]});

                        while (pre<next && nums[pre] == nums[pre + 1]) {
                            pre++;
                        }

                        while (pre<next && nums[next] == nums[next - 1]) {
                            next--;
                        }

                        pre++;
                        next--;
                    }
                    else if (sum < target) {
                        pre++;
                    }
                    else {
                        next--;
                    }
                }
            }
        }

        return qu;
    }
};
