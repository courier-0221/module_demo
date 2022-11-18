#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第四天 双指针

class Solution {
public: 
    string reverseWords(string s) {
        int length = s.length();
        int i = 0;
        while (i < length) 
        {
            int start = i;
            while (i < length && s[i] != ' ') 
            {
                i++;
            }

            int left = start, right = i - 1;
            while (left < right) 
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            // 越过空格
            while (i < length && s[i] == ' ') 
            {
                i++;
            }
        }
        return s;
    }
};

int main(void)
{
    Solution s;
    string s1("Let's take LeetCode contest");
    string ret1 = s.reverseWords(s1);
    printf("%s\n", ret1.c_str());

    return 0;
}