class Solution {
public:
    int strStr(string haystack, string needle) {

        int flag = static_cast<int>(haystack.find(needle));
        
        if (flag >= 0 && flag < static_cast<int>(haystack.size())) {
            return flag;
        }
        
        return -1;
    }
};
