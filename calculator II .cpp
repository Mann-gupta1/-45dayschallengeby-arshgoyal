class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            } else if (isdigit(s[i])) {
                int count = 0;
                while (i < s.size() && isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                i--; 
                operands.push(count);
            } else if (s[i] == '(') {
                operators.push('(');
            } else if (s[i] == ')') {
                while (operators.top() != '(') {
                    func2(operands, operators);
                }
                operators.pop();
                } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                while (!operators.empty() && func1(s[i], operators.top())) {
                    func2(operands, operators);
                }
                operators.push(s[i]);
            }
        }
        
        while (!operators.empty()) {
            func2(operands, operators);
        }
        
        return operands.top();
    }
    
private:
    bool func1(char op1, char op2) {
        if (op2 == '(' || op2 == ')') {
            return false;
        } else if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
            return false;
        }
        return true;
    }
    
    void func2(std::stack<int>& operands, std::stack<char>& operators) {
        int b = operands.top();
        operands.pop();
        int a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        
        int flag;
        switch (op) {
            case '+':
                flag = a + b;
                break;
            case '-':
                flag = a - b;
                break;
            case '*':
                flag = a * b;
                break;
            case '/':
                flag = a / b;
                break;
        }
        
        operands.push(flag);
    }
};
