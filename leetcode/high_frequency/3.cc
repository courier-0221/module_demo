#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/*
思路：
滑动窗口
其实就是一个队列,比如例题中的 abcabcbb，进入这个队列（窗口）为 abc 满足题目要求，当再进入 a，队列变成了 abca，这时候不满足要求。所以，我们要移动这个队列！
如何移动？
我们只要把队列的左边的元素移出就行了，直到满足题目要求！
*/

/*
滑动窗口类似题目
3、30、76、159、209、239、567、632、727
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int left = 0, maxStr = 0;
        unordered_set<char> lookup;
        for (int i = 0; i < s.size(); i++)
        {
            while (lookup.count(s[i]) != 0)
            {
                lookup.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
};

int main(void)
{
    Solution s;
    printf("%d\n", s.lengthOfLongestSubstring("abcabcc"));
    return 0;
}