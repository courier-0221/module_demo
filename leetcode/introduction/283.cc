#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第三天 双指针

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size())
        {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
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
    vector<int> arr = {0,1,0,3,12};
    s.moveZeroes(arr);
    print_vec(arr);
    return 0;
}