#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// 单词拆分
// 思路：回溯法解决，和131题分割回文串类似，将wordDict放入set中，然后将字符串进行切割，切割出来的所有字串包含 == wordDict中的内容就说明正确
// 时间优化：使用memory数组保存每次计算的以startIndex起始的计算结果，如果memory[startIndex]里已经被赋值了，直接用memory[startIndex]的结果。

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), 1); // -1 表示初始化状态
        return backtracking(s, wordSet, memory, 0);
    }

private:
    
    bool backtracking(string &s, unordered_set<string> wordSet, vector<bool> &memory, int startIndex)
    {
        if (startIndex >= s.size()) {
            return true;
        }
        // 如果memory[startIndex]不是初始值了，直接使用memory[startIndex]的结果
        if (!memory[startIndex]) return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, memory, i + 1)) {
                return true;
            }
        }
        memory[startIndex] = false; // 记录以startIndex开始的子串是不可以被拆分的
        return false;
    }
};

void test1(void)
{
    Solution s;
    string str("leetcode");
    vector<string> wordDirt = {"leet", "code"};
    cout << s.wordBreak(str, wordDirt) << endl;
}

void test2(void)
{
    Solution s;
    string str("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    vector<string> wordDirt = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << s.wordBreak(str, wordDirt) << endl;
}

int main(void)
{
    test1();
    test2();
    return 0;
}