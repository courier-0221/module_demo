#include <iostream>
#include <vector>
using namespace std;

// 买股票II
//「贪心算法」 和 「动态规划」、「回溯搜索」 算法一样，完成一件事情，是 分步决策 的；

// 贪心法：针对这道题特殊解法
//「贪心」 的地方在于，对于 「今天的股价 - 昨天的股价」，得到的结果有 3 种可能：正数，0，负数。贪心算法的决策是： 只加正数 。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0, maxMenoy = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            diff = prices[i] - prices[i - 1];
            if (diff > 0)
                maxMenoy += diff;
        }
        return maxMenoy;
    }
};

int main(void)
{
    Solution s;
    vector<int> prices1 = {7,1,5,3,6,4};
    printf("maxMenoy:%d\n", s.maxProfit(prices1));
    vector<int> prices2 = {1,2,3,4,5};
    printf("maxMenoy:%d\n", s.maxProfit(prices2));

    return 0;
}