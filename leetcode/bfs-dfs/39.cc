#include <iostream>
#include <vector>
using namespace std;

// 组合总和

// 回溯法解决
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    
    void backtracking(vector<int>& candidates, int target, int index) {
        int sum = 0;
        for (auto i : path)
            sum += i;
        if (sum == target) {
            result.push_back(path);
            return;
        }
        else if (sum > target)
        {
            return;
        }

        
        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]); // 处理节点 
            backtracking(candidates, target, i); // 递归，不用i+1了，表示可以重复读取当前的数
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear(); 
        path.clear();
        backtracking(candidates, target, 0);
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
    vector<int> arr1 = {2,3,6,7};
    vector<vector<int>> ret1 = s.combinationSum(arr1, 7);
    printf_arr2(ret1);

    vector<int> arr2 = {2,3,5};
    vector<vector<int>> ret2 = s.combinationSum(arr2, 8);
    printf_arr2(ret2);

    return 0;
}