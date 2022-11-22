#include <iostream>
#include <vector>
using namespace std;

// 最大子数组和
// 思路：这里采用动态规划的方式，，，动态规划善于求最值
// 首先计算出每一个元素前面元素集合的最大值，计算方式为拿 当前元素值 ？ 当前元素前的最大值+当前元素值 做对比，取最大值
// 然后从计算出的结果集中取出最大值

class Solution {
public:

    // 时间复杂度O(n) 空间复杂度O(n)
    int maxSubArrayLow(vector<int>& nums) {
        int pre = 0, maxValue = 0, index = 0;
        vector<int> process(nums.size());
        // 计算当前元素前面元素集合的最大值
        for (int num : nums)
        {
            pre = max(pre + num, num);
            process[index++] = pre;
        }

        // 从集合中找出最大值
        maxValue = process[0];
        for (int i = 0; i < process.size(); i++)
        {
            if (maxValue < process[i]) 
                maxValue = process[i];
        }

        return maxValue;
    }

    // 升级版本 时间复杂度O(n) 空间复杂度O(1)
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxValue = nums[0];
        for (int num : nums)
        {
            pre = max(pre + num, num);
            maxValue = max(maxValue, pre);
            printf("pre=%d\t maxValue=%d\n", pre, maxValue);
        }

        return maxValue;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    printf("max:%d\n", s.maxSubArrayLow(nums1));
    return 0;
}