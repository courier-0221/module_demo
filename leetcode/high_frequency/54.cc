#include <iostream>
#include <vector>
using namespace std;

// 螺旋矩阵
/*
思路：
1.首先设定上下左右边界
2.其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
3.判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
4.若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
5.不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
*/

// 一次过程：向右--向下--向左--向上  要点：重点控制好上下左右四个边界

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector <int> ans;
        if (matrix.empty()) return ans;
        int upper = 0; 
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (true)
        {
            for(int i = left; i <= right; ++i) 
                ans.push_back(matrix[upper][i]); //向右
            if(++ upper > down) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            
            for(int i = upper; i <= down; ++i) 
                ans.push_back(matrix[i][right]); //向下
            if(-- right < left) break; //重新设定右边界
            
            for(int i = right; i >= left; --i) 
                ans.push_back(matrix[down][i]); //向左
            if(-- down < upper) break; //重新设定下边界
            
            for(int i = down; i >= upper; --i) 
                ans.push_back(matrix[i][left]); //向上
            if(++ left > right) break; //重新设定左边界
        }
        return ans;
    }
};

void printf_vector(vector<int> &arr)
{
    for (int i : arr)
    {
        printf("%d\t", i);
    }
    printf("\n");
}

void test1(void)
{
    Solution s;
    vector< vector<int> > arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ret = s.spiralOrder(arr);
    printf_vector(ret);
}

void test2(void)
{
    Solution s;
    vector< vector<int> > arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ret = s.spiralOrder(arr);
    printf_vector(ret);
}

int main(void)
{
    test1();
    test2();

    return 0;
}