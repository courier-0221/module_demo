#include <iostream>
#include <vector>
using namespace std;

// 颜色分类
// 思路，统计出0，1，2个数，然后按照0，1，2顺序写入到原数组中

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_0 = 0, count_1 = 0, count_2 = 0;
        for (auto i : nums)
        {
            if (0 == i) count_0++;
            else if (1 == i) count_1++;
            else if (2 == i) count_2++;
        }

        for (int i = 0; i < count_0; i++)
            nums[i] = 0;
        for (int i = count_0; i < count_0 + count_1; i++)
            nums[i] = 1;
        for (int i = count_0 + count_1; i < count_0 + count_1 + count_2; i++)
            nums[i] = 2;
    }
};

void printf_arr(vector<int>& nums)
{
    for (auto i : nums)
        printf("%d\t", i);
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<int> arr1 = {2,0,2,1,1,0};
    s.sortColors(arr1);
    printf_arr(arr1);


    return 0;
}