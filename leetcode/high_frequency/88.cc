#include <iostream>
#include <vector>
using namespace std;

// 合并两个有序数组
// 参考思路：https://leetcode.cn/problems/merge-sorted-array/solutions/126371/88-by-ikaruga/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        m--; n--;
        while (n >= 0)
        {
            // 反向遍历nums1中有效位置元素，将所有比nums2中反向第一个元素大的数字按照顺序都挪到nums1的末尾
            // 然后挪动m和i的位置
            while(m >= 0 && nums1[m] > nums2[n])
            {
                swap(nums1[i--], nums1[m--]);
            }

            // 经过前面的步骤后到这里一定是nums1[m] < nums2[n],互换下然后继续走到第一步
            swap(nums2[n--], nums1[i--]);
        }
    }
};

void printf_arr(vector<int>& arr)
{
    for (int i: arr)
        printf("%d\t", i);
    printf("\n");
}

void test1(void)
{
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);
    printf_arr(nums1);
}

void test2(void)
{
    Solution s;
    vector<int> nums1 = {1};
    vector<int> nums2;
    s.merge(nums1, 1, nums2, 0);
    printf_arr(nums1);
}

int main(void)
{
    test1();
    test2();

    return 0;
}