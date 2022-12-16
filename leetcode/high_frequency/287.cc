#include <iostream>
#include <vector>
using namespace std;

// 寻找重复数
// 前提是不修改数组，使用常量级别O(1)的额外空间，限制了不能排序，不能使用额外空间

// 思路：二分查找
// 数组5个元素 里面的值是在[1,4]之间，且只有一个重复元素
// 统计数组中小于等于k的数字的个数count
// 若count<=k，说明重复数字一定在(k, n-1]的范围内
// 若count>k，说明重复数字一定在[0, k]的范围内

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

    }
};