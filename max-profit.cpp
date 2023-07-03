class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumprice = INT_MAX; 
        int maximumprice = 0;
        for (int price : prices) {
            minimumprice = min(minimumprice, price); 
            maximumprice = max(maximumprice, price - minimumprice);
            
        }
        
        return maximumprice;
    }
};
