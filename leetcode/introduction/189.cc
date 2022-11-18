#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第二天 双指针

// 这里没有用到双指针

// 复制一个数组，空间复杂度O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; i++)
        {
            newArr[(i+k)%n] = nums[i];
        }
        nums.assign(newArr.begin(), newArr.end());
    }
};

// 空间复杂度可以为O(1)
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        
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
    vector<int> arr = {1,2,3,4,5,6,7};
    s.rotate(arr, 3);
    print_vec(arr);

    return 0;
}