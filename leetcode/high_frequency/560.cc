#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_sum_map;
        prefix_sum_map[0] = 1;  // 初始化，表示和为0的前缀和出现过1次
        int prefix_sum = 0;  // 当前前缀和
        int count = 0;  // 符合条件的子数组个数
        
        for (int num : nums) {
            prefix_sum += num;  // 更新前缀和

            // 如果存在 prefix_sum - k 在哈希表中，说明有子数组和为 k
            if (prefix_sum_map.find(prefix_sum - k) != prefix_sum_map.end()) {
                count += prefix_sum_map[prefix_sum - k];  // 增加子数组个数
            }

            // 将当前的前缀和加入哈希表
            prefix_sum_map[prefix_sum]++;
        }

        return count;
    }
};

// //暴力方式
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             int sum = 0;
//             for (int j = i; j >= 0; j--) {
//                 sum += nums[j];
//                 if (sum == k) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

void test1() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << "result: " << s.subarraySum(nums, 3) << endl;
}

void test2() {
    Solution s;
    vector<int> nums = {1, 1, 1};
    cout << "result: " << s.subarraySum(nums, 2) << endl;
}

void test3() {
    Solution s;
    vector<int> nums = {1,-1,0};
    cout << "result: " << s.subarraySum(nums, 0) << endl;
}

void test4() {
    Solution s;
    vector<int> nums = {6,4,3,1};
    cout << "result: " << s.subarraySum(nums, 10) << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}