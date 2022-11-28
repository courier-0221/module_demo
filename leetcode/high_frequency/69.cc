#include <iostream>
#include <vector>
using namespace std;

// x的平方根
// 思路: 二分查找

class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x, ret = -1;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if ((long long) mid * mid <= x)
            {
                ret = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    printf("%d\n", s.mySqrt(4));
    printf("%d\n", s.mySqrt(8));
    printf("%d\n", s.mySqrt(0));
    printf("%d\n", s.mySqrt(1));
    printf("%d\n", s.mySqrt(2));
    printf("%d\n", 3+(4-1)>>1);
    printf("%d\n", 3+(4-1)/2);

    return 0;
}