#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 电话号码字母的组合

// 回溯法解决
class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

private:
    vector<string> result; // 存放符合条件结果的集合
    string path; // 用来存放符合条件结果
    void backtracking(string digits, int index) {
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = letterMap[digit];      // 取数字对应的字符集
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]); // 处理节点 
            backtracking(digits, index + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        result.clear(); 
        path.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
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
    vector<string> ret1 = s.letterCombinations("23");
    printf_arr2(ret1);

    vector<string> ret2 = s.letterCombinations("2");
    printf_arr2(ret2);

    return 0;
}