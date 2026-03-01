#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 括号生成器

// 回溯法解决
class Solution {

private:
    vector<string> result; // 存放符合条件结果的集合
    string path; // 用来存放符合条件结果
    
    void backtracking(int open, int close, int n) {
        if (path.size() == n*2)
        {
            result.push_back(path);
            return;
        }

        if (open < n)   // 还有左半部分可以用，优先使用
        {
            path.push_back('(');
            backtracking(open + 1, close, n);
            path.pop_back();
        }

        if (close < open)   // 右半部分个数小于左半部分个数可以使用右半部分
        {
            path.push_back(')');
            backtracking(open, close + 1, n);
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        result.clear(); 
        path.clear();
        backtracking(0, 0, n);
        return result;
    }
};

void printf_arr2(vector<string> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%s\n", arr[i].c_str());
    }
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<string> ret1 = s.generateParenthesis(3);
    printf_arr2(ret1);

    vector<string> ret2 = s.generateParenthesis(2);
    printf_arr2(ret2);

    return 0;
}