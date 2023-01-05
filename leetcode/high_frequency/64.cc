#include <iostream>
#include <vector>
using namespace std;

// 最小路径和

// 思路：
// 动态规划解决   和62题 不同路径类似
// 当 i>0 且 j=0 时，dp[i][0]=dp[i−1][0]+grid[i][0]。
// 当 i=0 且 j>0 时，dp[0][j]=dp[0][j−1]+grid[0][j]。
// 当 i>0 且 j>0 时，dp[i][j]=min⁡(dp[i−1][j],dp[i][j−1])+grid[i][j]。

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(); 
        vector<vector<int>> dp(row, vector<int>(column));

        dp[0][0] = grid[0][0];

        for (int i = 1; i < row; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        
        for (int j = 1; j < column; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < column; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[row-1][column-1];
    }
};

int main(void)
{
    Solution s;
    vector<vector<int>> grid1 = {{1,3,1},{1,5,1},{4,2,1}};
    printf("%d\n", s.minPathSum(grid1));
    vector<vector<int>> grid2 = {{1,2,3},{4,5,6}};
    printf("%d\n", s.minPathSum(grid2));
    return 0;
}