#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第一天 二分查找

#define INPUT_N (4)
static int gCallCount = 0;

// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
    gCallCount++;
    if (version >= INPUT_N)
        return true;
    else
        return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;   // 防止计算时溢出
            if (true == isBadVersion(mid))
            {
                high = mid;     // 答案在区间 [low, mid]
            }
            else
            {
                low = mid + 1;  // 答案在区间 [mid+1, high]
            }
        }
        return low;
    }
};

int main(void)
{
    Solution s;
    printf("%d\n", s.firstBadVersion(5));
    printf("gCallCount: %d\n", gCallCount);

    return 0;
}