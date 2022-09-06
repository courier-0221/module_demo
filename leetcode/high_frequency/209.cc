#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
思路：使用滑动窗口来实现

初始：
定义两个指针 start 和 end 分别表示子数组（滑动窗口窗口）的开始位置和结束位置，维护变量 sum 存储子数组中的元素和（即从 nums[start] 到 nums[end] 的元素和）。
初始状态下，start 和 end 都指向下标 00，sum 的值为 00。

逻辑：
每一轮迭代，将 nums[end]加到 sum，如果 sum >= s，则更新子数组的最小长度（此时子数组的长度是 end-start+1），
然后将 nums[start] 从 sum 中减去并将 start 右移，直到 sum < s，在此过程中同样更新子数组的最小长度。在每一轮迭代的最后，将 end 右移。
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (0 == nums.size())   return 0;
        
        int start = 0, end = 0;
        int length = INT_MAX, sum = 0;

        while (end < nums.size())
        {
            sum += nums[end];
            while (sum >= target)
            {
                length = min(length, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }

        return length == INT_MAX ? 0 : length;
    }
};

int main(void)
{
    vector<int> arr = {1,2,3,4,5};
    int target = 11;

    Solution s;
    printf("%d\n", s.minSubArrayLen(target, arr));
    
    return 0;
}