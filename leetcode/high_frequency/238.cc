#include <iostream>
#include <vector>
using namespace std;

void print_arr(vector<int> &arr);

// 除自身以外数组的乘积
// 思路：
// 左右乘积办法解决

//    4 5 1 8 2
// l: 1    4 20 20 160
// r: 80  16 16 2  1
// answer[i] = l[i] * r[i]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> L(size, 0);
        vector<int> R(size, 0);
        vector<int> answer(size, 0);

        L[0] = 1;
        for (int i = 1; i < size; i++)
        {
            L[i] = nums[i-1] * L[i-1];
        }
        R[size-1] = 1;
        for (int i = size - 2; i >=0; i--)
        {
            R[i] = nums[i+1] * R[i+1];
        }
        for (int i = 0; i < size; i++)
        {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};

void print_arr(vector<int> &arr)
{
    for (int i : arr)
        printf("%d\t", i);
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<int> nums1 = {1,2,3,4};
    vector<int> ret1 = s.productExceptSelf(nums1);
    print_arr(ret1);
    return 0;
}