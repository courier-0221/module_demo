#include <iostream>
#include <vector>
using namespace std;

// 跳跃游戏
// 思路：
//     记录从左到右遍历过程种最远可以到达的距离

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0; //可到达的最远距离
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            // 当前位置在最远到达范围内
            if (furthest >= i)
            {
                furthest = max(furthest, i + nums[i]);  // 当前位置+可跳转的距离 vs 历史最大可到达的最远距离
                if (furthest >= size - 1)
                    return true;
            }
        }

        return false;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {2,3,1,1,4};
    cout << s.canJump(arr1) << endl;

    vector<int> arr2 = {3,2,1,0,4};
    cout << s.canJump(arr2) << endl;

    return 0;
}