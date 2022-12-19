#include <iostream>
#include <vector>
using namespace std;

// 寻找重复数
// 前提是不修改数组，使用常量级别O(1)的额外空间，限制了不能排序，不能使用额外空间

// 思路：二分查找
// 数组5个元素 里面的值是在[1,4]之间，且只有一个重复元素
// 统计数组中小于等于k数字的个数count
// 若count<=k，说明重复数字一定在(k, n-1]的范围内
// 若count>k，说明重复数字一定在[0, k]的范围内

// [1,3,4,2,2]
// nums: 1 2 3 4
// cnt:  1 3 4 5    (<=1 <=2 <=3 <=4的元素个数)

// 实现：
// 使用数组下标进行二分，决定使用哪一半的条件为：统计数组中小于等于k数字的个数count，然后判定在哪个区间

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, mid = -1, count = 0, ret = -1;
        
        while (low <= high)
        {
            count = 0;
            mid = low + ((high - low) >> 1);
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] <= mid)
                {
                    count++;
                }
            }

            if (count <= mid)
            {
                low = mid + 1;
            }
            else if (count > mid)
            {
                high = mid - 1;
                ret = mid;
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {1,3,4,2,2};
    printf("%d\n", s.findDuplicate(arr1));

    vector<int> arr2 = {3,1,3,4,2};
    printf("%d\n", s.findDuplicate(arr2));

    return 0;
}