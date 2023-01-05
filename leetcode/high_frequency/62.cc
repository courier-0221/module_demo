#include <iostream>
#include <vector>
using namespace std;

// 不同路径

// 思路：
// 动态规划解决
// 用 f(i,j) 表示从左上角走到 (i,j) 的路径数量，其中 i 和 j 的范围分别是 [0,m) 和 [0,n)。
// 由于我们每一步只能从向下或者向右移动一步，因此要想走到 (i,j)，如果向下走一步，那么会从 (i−1,j) 走过来；如果向右走一步，那么会从 (i,j−1) 走过来。因此我们可以写出动态规划转移方程：
// f(i,j)=f(i−1,j)+f(i,j−1)

// 最左一列和最上面一行初始值为1

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            matrix[i][0] = 1;
        
        for (int j = 0; j < n; j++)
            matrix[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }

        return matrix[m-1][n-1];
    }
};

int main(void)
{
    Solution s;
    printf("%d\n", s.uniquePaths(3, 7));
    printf("%d\n", s.uniquePaths(3, 2));
    printf("%d\n", s.uniquePaths(7, 3));
    printf("%d\n", s.uniquePaths(3, 3));
    return 0;
}