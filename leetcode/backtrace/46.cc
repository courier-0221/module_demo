#include <iostream>
#include <vector>
using namespace std;

// 全排列

// 回溯法解决
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
    
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
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
    vector<vector<int>> ret1 = s.permute(arr1);
    printf_arr2(ret1);

    vector<int> arr2 = {2,3,5};
    vector<vector<int>> ret2 = s.permute(arr2);
    printf_arr2(ret2);

    return 0;
}