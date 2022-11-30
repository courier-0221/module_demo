#include <iostream>
#include <vector>
#include <string>
using namespace std;

//leetcode 算法入门 第六天 滑动窗口 
// 567题 字符串的排列
// 思路：
// 分析一： 题目要求 s1 的排列之一是 s2 的一个子串。而子串必须是连续的，所以要求的 s2 子串的长度跟 s1 长度必须相等。
// 分析二： 那么我们有必要把 s1 的每个排列都求出来吗？当然不用。如果字符串 a 是 b 的一个排列，那么当且仅当它们两者中的每个字符的个数都必须完全相等。
// 所以，根据上面两点分析，我们已经能确定这个题目可以使用 滑动窗口 + 字典 来解决。

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.size();
        int s2len = s2.size();
        int count[256] = {0};
        int left = 0, right = 0;

        // 统计 s1 中每个字符出现的次数
        for (int i = 0; i < s1len; i++)
            count[s1[i]]++;

        // 定义滑动窗口的范围是 [left, right]，闭区间，长度与s1相等
        left = 0;
        right = s1len - 1;
        
        while (right < s2len)
        {
            // 统计滑动窗口里面每个字符串出现的次数
            int window_count[256] = {0};
            for (int i = left; i <= right; i++)
                window_count[s2[i]]++;
            
            // 将窗口里面统计值和s1的统计值做对比
            int i = 0;
            for (i = 0; i < s1len; i++)
            {
                if (window_count[s1[i]] != count[s1[i]])
                {
                    break;
                }
            }
            // 完全相等则说明s2包含s1的组合
            if (i == s1len)  return true;
            
            // 窗口向右移动
            left++;
            right++;
        }
        return false;
    }
};

void test1(void)
{
    Solution s;
    string s1("ab");
    string s2("eidbaooo");
    cout << "result: " << s.checkInclusion(s1, s2) << endl;
}

void test2(void)
{
    Solution s;
    string s1("ab");
    string s2("eidboaoo");
    cout << "result: " << s.checkInclusion(s1, s2) << endl;
}

void test3(void)
{
    Solution s;
    string s1("abc");
    string s2("bbbca");
    cout << "result: " << s.checkInclusion(s1, s2) << endl;
}

int main(void)
{
    test1();
    test2();
    test3();

    return 0;
}