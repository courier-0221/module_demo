#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int knapsack(vector<int>& wt, vector<int>& val)
    {
        vector<vector<int>> dp;
        dp.resize(wt.size()+1);
        for (int i = 0; i <= val.size(); i++)
            dp[i].resize(val.size()+1);

        for (int i = 1; i <= wt.size(); i++)
        {
            for (int j = 1; j <= val.size(); j++)
            {
                if (wt[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
            }
        }

        //输出dp表
        for (int i = 0; i <= wt.size(); i++){
            for (int j = 0; j <= val.size(); j++){
                printf("%d\t", dp[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        return dp[wt.size()][val.size()];
    }
};

void test1(void)
{
    vector<int> wt = {2,1,3};
    vector<int> val = {4,2,3};
    Solution s;
    printf("%d\n", s.knapsack(wt, val));
}

int main(void)
{
    test1();
    return 0;
}