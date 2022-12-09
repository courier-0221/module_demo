#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 合并区间
// 思路：参考官方解法
// 首先排序，按照左端点升序排序，然后对排序后的结果进行操作
// 如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
// 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) 
        {
            int L = intervals[i][0], R = intervals[i][1];
            // 第一个元素直接加入到数组，非第一个元素需要判断 左端点 > 已合并数组最后一个元素的右端点说明跨区间了，需要加入到merged
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            // 这里说明数组中的元素盒merged最后一个元素有交集，直接合并右端点就行
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

void printf_arr(vector<vector<int>>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void test1(void)
{
    Solution s;
    vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ret = s.merge(nums);
    printf_arr(ret);
}

void test2(void)
{
    Solution s;

}

int main(void)
{
    test1();

    return 0;
}