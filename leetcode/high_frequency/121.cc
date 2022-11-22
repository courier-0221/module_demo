#include <iostream>
#include <vector>
using namespace std;

// 买股票的最佳时机，什么时候买能获得最大收益

// 思路就是买股票一定要在最低为买入最高位卖出才能获得最大收益
// 记录到今天为止的价格的历史最低值，然后记录 当天的价格-历史价格最低值 这样一个价格差，保存这个价格差的最大值

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e9, maxMenoy = 0;
        for (int price : prices)
        {
            minPrice = min(minPrice, price);
            maxMenoy = max(maxMenoy, price - minPrice);
        }

        return maxMenoy;
    }
};

int main(void)
{
    Solution s;
    vector<int> prices1 = {4,3,2,1,5,6,7};
    printf("max:%d\n", s.maxProfit(prices1));
    vector<int> prices2 = {7,6,5,4,3,2,1};
    printf("max:%d\n", s.maxProfit(prices2));


    return 0;
}