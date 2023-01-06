#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <limits.h>
using namespace std;

// 最长连续序列  要求时间复杂度O(n)
// 思路：


// 使用set实现超时(自动排序的红黑树)
#if 0
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> nums_set;
        for (auto i : nums)
            nums_set.insert(i);
        
        int max_len = 0, count = 1;
        set<int>::iterator it = nums_set.begin();
        int histroy = *it;
        // it 从第二个元素开始  当前元素和前一个元素做比较是否相差1，如果不是说明出现了断层，判断长度是不是最长的
        for (it++; it != nums_set.end(); it++)
        {
            if ((histroy+1) == *it)
                count++;
            else
                count = 1;
            
            max_len = max(max_len, count);
            histroy = *it;
        }

        return max_len;
    }
};
#endif

// 使用unordered_set （hash表)实现
// 思路，使用hash表存储数组元素，做一个过滤操作，然后对hash表中的每一个元素做如下判定
// 如果它的cur-1值在hash表中存在则不统计，如果不存在则统计，一直判断cur+1不在hash表中存在了
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // 建立一个存储所有数的哈希表，同时起到去重功能
        unordered_set<int> nums_set;
        for (auto i : nums)
            nums_set.insert(i);
        
        // 遍历去重后的所有数字
        int max_len = 0;
        for (auto num : nums_set)
        {
            int cur = num;
            // 只有当num-1不存在时，才开始向后遍历num+1，num+2，num+3......
            if (!nums_set.count(cur - 1)) {
                while (nums_set.count(cur + 1)) {
                    cur++;
                }
            }
            // [num, cur]之间是连续的，数字有cur - num + 1个
            max_len = max(max_len, cur - num + 1);
        }

        return max_len;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {100,4,200,1,3,2};
    printf("%d\n", s.longestConsecutive(arr1));
    vector<int> arr2 = {0,3,7,2,5,8,4,6,0,1};
    printf("%d\n", s.longestConsecutive(arr2));
    return 0;
}