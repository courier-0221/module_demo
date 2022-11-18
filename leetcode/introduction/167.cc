#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第三天 双指针

//这道题可以使用「1. 两数之和」的解法,借助哈希表使用O(n)的时间复杂度和O(n)的空间复杂度求解。
//但是这两种解法都是针对无序数组的，没有利用到输入数组有序的性质。利用输入数组有序的性质，可以得到时间复杂度和空间复杂度更优的解法。

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;

        while (low < high)
        {
            int sum = numbers[low] + numbers[high];
            if (sum > target)
            {
                high--;
            }
            else if (sum < target)
            {
                low++;
            }
            else
            {
                return {low+1, high+1};
            }
        }        

        return {-1, -1};
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
    vector<int> arr1 = {2,7,11,15};
    vector<int> ret1 = s.twoSum(arr1, 9);
    print_vec(ret1);

    vector<int> arr2 = {-1,0};
    vector<int> ret2 = s.twoSum(arr2, -1);
    print_vec(ret2);
    return 0;
}