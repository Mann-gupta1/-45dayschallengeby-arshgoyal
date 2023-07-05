class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (cardPoints.size() == k) {
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += cardPoints[i];
            }
            return sum;
        }

        int maxSum = 0;
        int n = cardPoints.size();
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        maxSum = sum;

        for (int i = 0; i < k; i++) {
            sum = sum - cardPoints[k - i - 1] + cardPoints[n - i - 1];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
