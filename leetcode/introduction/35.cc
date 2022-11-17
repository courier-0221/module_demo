#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第一天 二分查找

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
                return low;
        }
        return low;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums = {1,3,5,6};
    printf("%d\n", s.searchInsert(nums, 2));
    printf("%d\n", s.searchInsert(nums, 5));
    printf("%d\n", s.searchInsert(nums, 7));
    return 0;
}