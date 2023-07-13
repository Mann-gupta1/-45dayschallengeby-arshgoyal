class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                a.push(c);
            } else {
                if (a.empty()) {
                    return false;
                }
                char last = a.top();
                a.pop();
                if ((c == ')' && last != '(') || (c == ']' && last != '[') || (c == '}' && last != '{')) {
                    return false;
                }
            }
        }
        return a.empty();
    }
};
