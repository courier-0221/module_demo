#include <iostream>
#include <stack>
using namespace std;

// 有效的括号

// 思路：使用栈解决

class Solution {
public:
    bool isValid(string s) {
        stack<int> sk;
        for (char c : s) {
            if (('(' == c) || ('[' == c) || ('{' == c)) {
                sk.push(c);
            } else {
                //右括号：三种情况
                //1.栈为空，false
                //2.与栈顶元素不匹配，false
                //3.与栈顶元素匹配，true，并将栈顶元素出栈
                if (sk.empty()) {
                    return false;
                } 

                if ((c == ')') && (sk.top() == '(')) {
                    sk.pop();
                } else if ((c == ']') && (sk.top() == '[')) {
                    sk.pop();
                } else if ((c == '}') && (sk.top() == '{')) {
                    sk.pop();
                } else {
                    return false;
                }
            }
        }

        return sk.empty();
    }
};

int main(void) {
    Solution s;
    string s1("(){}[]");
    cout << s.isValid(s1) << endl;
    
    string s2("(){[]");
    cout << s.isValid(s2) << endl;

    return 0;
}