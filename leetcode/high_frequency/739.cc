#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 每日温度
// 思路：
// 使用栈来实现，栈中元素分布方式为 栈底-->栈顶  大-->小 ,栈中存储的是元素下标，代表第几天

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        s.push(0);  // 先放进去第一天的温度下标
        vector<int> result(temperatures.size());
        
        for (int i = 1; i < temperatures.size(); i++)
        {
            // 如果当天温度大于栈顶的温度，找到了最合适的值
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int old = s.top();
                s.pop();
                result[old] = i - old;
            }

            // 如果当天温度小于栈顶的温度，将当天温度入栈
            s.push(i);
        }

        return result;
    }
};

void printf_vector(vector<int>& arr)
{
    for (int i : arr)
    {
        printf("%d\t", i);
    }
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<int> temp1 = {73,74,75,71,69,72,76,73};
    vector<int> ret1 = s.dailyTemperatures(temp1);
    printf_vector(ret1);

    vector<int> temp2 = {30,40,50,60};
    vector<int> ret2 = s.dailyTemperatures(temp2);
    printf_vector(ret2);

    vector<int> temp3 = {89,62,70,58,47,47,46,76,100,70};
    vector<int> ret3 = s.dailyTemperatures(temp3);
    printf_vector(ret3);

    return 0;
}