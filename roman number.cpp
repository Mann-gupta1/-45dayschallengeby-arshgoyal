class Solution {
public:
    string intToRoman(int num) {
        string temp = "";
        vector<int> a = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> exact = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        while (num > 0) {
            int k = num / a[i];
            for (int j = 0; j < k; j++) {
                temp += exact[i];
                num -= a[i];
            }
            i++;
        }
        return temp;
    }
};
