#include <iostream>
#include <vector>
using namespace std;

// 回溯法解决
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // 处理节点 
            backtracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); 
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};

void printf_arr2(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<vector<int>> ret1 = s.combine(4,2);
    printf_arr2(ret1);

    vector<vector<int>> ret2 = s.combine(1,1);
    printf_arr2(ret2);

    return 0;
}