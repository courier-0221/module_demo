#include <iostream>
#include <vector>
using namespace std;

// 子集

// 回溯法解决
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    
    void backtracking(vector<int>& nums, int index) {
        result.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (index >= nums.size()) {
            return;
        }
    
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]); // 处理节点 
            //result.push_back(path);
            backtracking(nums, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear(); 
        path.clear();
        backtracking(nums, 0);
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
    vector<vector<int>> ret1 = s.subsets(arr1);
    printf_arr2(ret1);

    vector<int> arr2 = {2,3,5};
    vector<vector<int>> ret2 = s.subsets(arr2);
    printf_arr2(ret2);

    return 0;
}