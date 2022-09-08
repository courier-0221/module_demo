#include <iostream>
#include <vector>

namespace v1
{
// 暴力递推解法 缺点是有很多重复计算
class Solution {
public:
    int fib(int n) {
        // base case
        if (0 == n || 1 == n) return n;
        // 递推关系
        int data = fib(n-1) + fib(n-2);
        return data;
    }
};

void test(void)
{
    Solution s;
    int n = 4;
    printf("fib(%d) = %d\n", n, s.fib(n));
}
}

namespace v2
{
// 备忘录的递归解法
class Solution {
public:
    int fib(int n) {
        _lookup.resize(n+1);
        // 带备忘录的递归
        return helper(_lookup, n);
    }

private:
    int helper(std::vector<int>& lookup, int n)
    {
        // base case
        if (0 == n || 1 == n) return n;
        // 已经计算过了不再计算
        if (_lookup[n] != 0) return _lookup[n];
        
        _lookup[n] = helper(_lookup, n-1) + helper(_lookup, n-2);
        
        return _lookup[n];
    }

private:
    std::vector<int> _lookup;
};

void test(void)
{
    Solution s;
    int n = 20;
    printf("fib(%d) = %d\n", n, s.fib(n));
}
}

namespace v3
{
// 动态规划解法 自底向上递推解法
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        // base case
        std::vector<int> dp(n+1, 0);
        dp[0] = 0, dp[1] = 1;
        // 穷举
        for (int i = 2; i <= n; i++)
        {
            // 状态转换
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

void test(void)
{
    Solution s;
    int n = 4;
    printf("fib(%d) = %d\n", n, s.fib(n));
}
}


int main(void)
{
    //v1::test();
    //v2::test();
    v3::test();
    return 0;
}
