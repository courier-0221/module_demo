#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 搜索旋转排序数组
// 思路：二分查找
// 需要特殊处理的地方是二分后一定有一半是升序的另一半有两个升序，判定标准是nums[mid] 是否大于 nums[low]
// 针对nums[high] > nums[low]情况则为正常的二分查找 需要判定target是否在里面人后重新指定low及high
// 针对nums[high] < nums[low]情况 需要判定target在哪一个子递增里面
//  如果 nums[mid]<target<=nums[high] 说明target在mid到high这一半中正常更改low
//  如果 nums[mid]<target,nums[high]<=target,说明target在两个子升序中，需要调整high


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 正常递增序列
            if (nums[mid] >= nums[low]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            // 包含两个递增序列
            } else {
                // 在正常递增的那一半调整low
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                // 在两个递增的那一半调整high
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums1 = {4,5,6,7,0,1,2};
    printf("%d\n", s.search(nums1, 1));
    vector<int> nums2 = {10,11,12,0,1,2,4,5,6,7};
    printf("%d\n", s.search(nums2, 1));

    return 0;
}