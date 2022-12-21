#include <iostream>
#include <vector>
using namespace std;

// 盛最多水的容器
// 思路：
// 使用双指针来解决
// https://leetcode.cn/problems/container-with-most-water/solutions/11491/container-with-most-water-shuang-zhi-zhen-fa-yi-do/
// i,j为指向指向水槽的两端，面积公式S(i,j)=min(h[i],h[j])×(j−i)
/* 
在每个状态下，无论长板或短板向中间收窄一格，都会导致水槽 底边宽度 −1​ 变短：
若向内 移动短板 ，水槽的短板 min(h[i],h[j]) 可能变大，因此下个水槽的面积 可能增大 。
若向内 移动长板 ，水槽的短板 min(h[i],h[j])​ 不变/变小/变大都有可能，但是短板位置没变底边宽度-1的情况下，因此下个水槽的面积 一定变小 。

所以向面积变大的可能的方向走，也就是比较两个边哪个短，然后将短的那一边向内移动
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int areas = 0;
        while (j > i)
        {
            if (height[i] > height[j])
            {
                areas = max(areas, height[j] * (j - i));
                j--;
            }
            else
            {
                areas = max(areas, height[i] * (j - i));
                i++;
            }
        }
        return areas;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {1,8,6,2,5,4,8,3,7};
    printf("%d\n", s.maxArea(arr1));

    vector<int> arr2 = {1,1};
    printf("%d\n", s.maxArea(arr2));

    return 0;
}