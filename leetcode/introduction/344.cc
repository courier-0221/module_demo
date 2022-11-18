#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第四天 双指针

class Solution {
public:
    void reverseString(vector<char>& s) {
        int low = 0, high = s.size() - 1;
        while (low < high)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }
};

void print_vec(vector<char>& input)
{
    for (auto i : input)
    {
        printf("%c\t", i);
    }
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<char> arr1 = {'h','e','l','l','0'};
    s.reverseString(arr1);
    print_vec(arr1);

    return 0;
}