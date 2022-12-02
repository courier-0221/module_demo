#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 搜索旋转排序数组
// 思路：二分查找
// 和33题查找某一个元素解法类似，使用二分查找
// 找到数组中间位置后一半是升序，一半是两个升序，判定nums[high]和nums[mid]的元素大小，然后逐步将high和low缩小到数值较小的那一方（根据mid调整high和low）

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;

        while (low < high)
        {
            mid = low + (high - low) / 2;
            // 一个递增那一半
            if (nums[mid] < nums[high])
            {
                high = mid;
            }
            // 两个递增那一半
            else
            {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};


int main(void)
{
    Solution s;
    vector<int> nums1 = {4,5,6,7,0,1,2};
    printf("%d\n", s.findMin(nums1));
    vector<int> nums2 = {10,11,12,0,1,2,4,5,6,7};
    printf("%d\n", s.findMin(nums2));

    return 0;
}