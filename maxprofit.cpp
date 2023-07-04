class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int total_profit = 0;

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                total_profit += prices[right] - prices[left];
            }
            left++;
            right++;
        }

        return total_profit;
    }
};
