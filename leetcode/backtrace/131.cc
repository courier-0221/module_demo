#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 分割回文串
// "aab"， 可以切割3刀，得到3个字串全是回文串'a'、'a'、'b'，也可以切割两刀得到2个字符串全是回文串"aa"、'b'
// 一定要保证切割出来的字串全是回文串，一共有多少种切法
// 思路：
// 回溯法解决
// 在for (int i = startIndex; i < s.size(); i++)循环中，我们 定义了起始位置startIndex，那么 [startIndex, i] 就是要截取的子串。

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(string s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return ;
        }
        
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i))
            {
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);// 注意切割过的位置，不能重复切割 所以寻找i+1为起始位置的子串
            path.pop_back();        // 回溯过程，弹出本次已经填在的子串
        }
    }

    bool isPalindrome(string &str, int start, int end)
    {
        while (start < end) {
            if (str[start] == str[end]) {
                start++; end--;
            } else {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};

void printf_arr2(vector<vector<string>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            printf("%s\t", arr[i][j].c_str());
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<vector<string>> ret1 = s.partition("aab");
    printf_arr2(ret1);
    return 0;
}