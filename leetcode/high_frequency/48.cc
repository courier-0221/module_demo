#include <iostream>
#include <vector>
using namespace std;

// 旋转图像
// 思路：
// 先水平反转，n行，(0,n-1)行互换，(1,n-2)行互换，(m, n-m+1) ,从下标0开始
// 再主对角线反转，沿着[0, n-1]这两个点连线，将两端元素互换。

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        // 水平反转
        for (int i = 0; i < size / 2; i++)
        {
            for (int j = 0; j < size; j++)
            {
                swap(matrix[i][j], matrix[size-1-i][j]);
            }
        }

        // 主对角线反转
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

void print_vec(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size() ; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void test1(void)
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(matrix);
    print_vec(matrix);
}

void test2(void)
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution s;
    s.rotate(matrix);
    print_vec(matrix);
}

int main(void)
{
    test1();
    test2();

    return 0;
}