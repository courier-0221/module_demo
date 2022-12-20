#include <iostream>
#include <vector>
using namespace std;

// 汉明距离
// 思路：
// 比较两个数字二进制最低位置的值是否相等，二进制最低的计算就是对2取余来求得。
// 也可以使用异或运算符，然后求异或运算后的数字二进制中有多少个1

class Solution {
public:
    int hammingDistance(int x, int y) {
        int remainder_x = -1, remainder_y = -1;
        int total = 0;
        while (x > 0 || y > 0)
        {
            remainder_x = -1, remainder_y = -1;
            remainder_x = x % 2;
            remainder_y = y % 2;

            if (remainder_x != remainder_y) total++;

            x = x >> 1;
            y = y >> 1;
        }

        return total;
    }
};

int main(void)
{
    Solution s;
    printf("%d\n", s.hammingDistance(1,4));
    printf("%d\n", s.hammingDistance(3,1));
    printf("%d\n", s.hammingDistance(93,73));

    return 0;
}