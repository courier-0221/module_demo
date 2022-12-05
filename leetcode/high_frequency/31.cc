#include <iostream>
#include <vector>
using namespace std;

// 下一个排列
// 思路：
/*
1.从后向前查找第一个相邻升序的元素对 (i,j)，满足 A[i] < A[j]。此时 [j,end) 必然是降序
2.在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k。A[i]、A[k] 分别就是上文所说的「小数」、「大数」
3.将 A[i] 与 A[k] 交换
4.可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序
5.如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4

作者：Imageslr
链接：https://leetcode.cn/problems/next-permutation/solutions/80560/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
            if (nums.size() <= 1) {
            return;
        }

	    int i = nums.size() - 2, j = nums.size() - 1, k = nums.size() - 1;

        // find: A[i]<A[j]
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }

        if (i >= 0) { // 不是最后一个排列
            // find: A[i]<A[k]
            while (nums[i] >= nums[k]) {
                k--;
            }
            // swap A[i], A[k]
            swap(nums[i], nums[k]);
        }

        // reverse A[j:end]
        for (i = j, j = nums.size()-1; i < j; i = i+1, j = j-1) {
            swap(nums[i], nums[j]);
        }
    }
};

void print_arr(vector<int> &nums)
{
    for (auto i : nums)
        printf("%d\t", i);
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<int> arr1 = {3,2,1};
    s.nextPermutation(arr1);
    print_arr(arr1);

    vector<int> arr2 = {1,2,3};
    s.nextPermutation(arr2);
    print_arr(arr2);
    
    return 0;
}