#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第二天 双指针

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        int boundary = -1;
        // 查找数组中非负数的分界，元素下标
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                boundary = i;   
            }
            else
            {
                break;
            }
        }

        //i j位置相邻
        int i = boundary, j = boundary + 1;
        while (i >= 0 || j < nums.size())
        {
            // 全是正数
            if (i == -1)
            {
                ret.push_back(nums[j] * nums[j]);
                j++;
            }
            // 全是负数
            else if (j == nums.size())
            {
                ret.push_back(nums[i] * nums[i]);
                i--;
            }
            else if (nums[i] * nums[i] <= nums[j] * nums[j])
            {
                ret.push_back(nums[i] * nums[i]);
                i--;
            }
            else if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                ret.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        return ret;
    }
};

void print_vec(vector<int>& input)
{
    for (auto i : input)
    {
        printf("%d\t", i);
    }
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<int> nums1 = {-4,-1,0,3,10};
    vector<int> nums2 = {-7,-3,2,3,11};
    vector<int> nums3 = {0,3,7,8,9,11};
    vector<int> nums4 = {-7,-6,-5,-4,-3};

    vector<int> ret1 = s.sortedSquares(nums1);
    print_vec(ret1);
    vector<int> ret2 = s.sortedSquares(nums2);
    print_vec(ret2);
    vector<int> ret3 = s.sortedSquares(nums3);
    print_vec(ret3);
    vector<int> ret4 = s.sortedSquares(nums4);
    print_vec(ret4);

    return 0;
}