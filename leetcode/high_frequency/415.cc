#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 字符串相加
// 思路：逐步位进行相加，双指针

class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.size() - 1, s2 = num2.size() - 1, add = 0;
        string result;
        while (s1 >= 0 || s2 >= 0 || add != 0)
        {
            int x = (s1 >= 0) ? (num1[s1] - '0') : 0;
            int y = (s2 >= 0) ? (num2[s2] - '0') : 0;
            int end = (x + y + add) % 10;
            add = (x + y + add) / 10;
            result.push_back(end + '0');
            s1--;
            s2--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

void test1(void)
{
    Solution s;
    string str1("456");
    string str2("77");
    printf("%s\n", s.addStrings(str1, str2).c_str());
}

void test2(void)
{
    Solution s;
    string str1("11");
    string str2("123");
    printf("%s\n", s.addStrings(str1, str2).c_str());
}

void test3(void)
{
    Solution s;
    string str1("0");
    string str2("0");
    printf("%s\n", s.addStrings(str1, str2).c_str());
}

int main(void)
{
    test1();
    test2();
    test3();

    return 0;
}