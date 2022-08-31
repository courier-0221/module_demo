#include <iostream>
#include <vector>
using namespace std;

/*
思路：
找每个柱子最左边最高的那个&最右边最高的那个柱子，幻想一下两个最高的柱子把自己夹在中间，
如果自己比两边最矮的柱子还矮那么就说明可以装雨水
如果自己比两边最矮的柱子还高那么就说明不可以装雨水
然后依次类推每根柱子

要点为使用动态规划记录下每根柱子为起始左边最高的那根柱子高度以及右边最高的那根柱子高度
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> left(len);
        vector<int> right(len);
        int area = 0;
        
        // 记录下每根柱子为起始左边最高的的柱子高度
        for (int i = 1; i < len; i++)
        {
            left[i] = max(left[i-1], height[i-1]);
        }

        // 记录下每根柱子为起始右边最高的的柱子高度
        for (int i = len - 2; i >= 0; i--)
        {
            right[i] = max(right[i+1], height[i+1]);
        }

        // 如果当前位置的柱子比最矮的那根还矮说明可以装雨水
        for (int i = 0; i < len; i++)
        {
            int betershort = min(left[i], right[i]);
            if (betershort > height[i])
            {
                area += betershort - height[i];
            }
        }

        return area;
    }
};

int main(void)
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;

    printf("%d\n", s.trap(arr));

    return 0;
}
