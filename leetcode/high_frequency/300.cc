#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最长递增子序列
// 求最值问题可以优先考虑动态规划
// 思路:参考官方提供的图片演示，主要为两次for循环，第二次for循环主要判定当前节点与前面的节点是否是递增的关系。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {10,9,2,5,3,7,101,18};
    printf("%d\n", s.lengthOfLIS(arr1));
    vector<int> arr2 = {7,7,7,7,7,7,7};
    printf("%d\n", s.lengthOfLIS(arr2));

    return 0;
}