#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//coinChange([1,2,5], 11)
//= 1 + min(coinChange([1,2,5], 10), coinChange([1,2,5], 9), coinChange([1,2,5], 6))

namespace v1
{
// 暴力递推解法 缺点是有很多重复计算
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // base case
        if (0 == amount) return 0;
        if (0 > amount) return -1;

        int ret = INT_MAX;

        for (auto i : coins)
        {
            // 计算子问题的结果
            int subProblem = coinChange(coins, amount-i);
            // 子问题无解则跳过
            if (subProblem < 0) continue;
            // 在子问题中选择最优解
            ret = min(ret, subProblem+1);
        }

        return ret == INT_MAX ? -1 : ret;
    }
};

void test()
{
    Solution s;
    vector<int> arr = {1,2,5};
    int amount = 11;
    printf("%d\n", s.coinChange(arr, amount));
}
}

namespace v2
{
// 备忘录的递归解法
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 填充特殊值
        vector<int> dp(amount+1, -666);
        return helper(coins, amount, dp);
    }
private:
    int helper(vector<int>& coins, int amount, vector<int>& dp)
    {
        // base case
        if (0 == amount) return 0;
        if (0 > amount) return -1;

        if (dp[amount] != -666)
            return dp[amount];

        int ret = INT_MAX;

        for (auto i : coins)
        {
            // 计算子问题的结果
            int subProblem = helper(coins, amount-i, dp);
            // 子问题无解则跳过
            if (subProblem < 0) continue;
            // 在子问题中选择最优解
            ret = min(ret, subProblem+1);
        }

        dp[amount] = ret == INT_MAX ? -1 : ret;

        return dp[amount];
    }
};

void test()
{
    Solution s;
    vector<int> arr = {1,2,5};
    int amount = 11;
    printf("%d\n", s.coinChange(arr, amount));
}
}

namespace v3
{
// 自底向上迭代解法
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1); // 初始化为特殊值

        // base case
        dp[0] = 0;
        // 外层 for 循环在遍历所有 状态 的所有取值
        for (int i = 0; i < dp.size(); i++)
        {
            // 内层 for 循环在求左右选择的最小值
            for (auto coin : coins)
            {
                // 子问题无解，跳过
                if (i - coin < 0) continue;
                // 状态转移
                dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }

        // 看看金额 amount 能不能凑出来
        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }
};

void test()
{
    Solution s;
    vector<int> arr = {1,2,5};
    int amount = 11;
    printf("%d\n", s.coinChange(arr, amount));
}
}

int main(void)
{
    //v1::test();
    //v2::test();
    v3::test();
    return 0;
}