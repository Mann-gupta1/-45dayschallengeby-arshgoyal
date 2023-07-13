class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string flag = strs[0]; 
        
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(flag) != 0) {
                flag = flag.substr(0, flag.length() - 1); 
                
            }
        }
        
        return flag;
    }
};
