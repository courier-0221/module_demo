// 虚函数可以是内联函数么

#include <iostream>
#include <vector>
using namespace std;

// 2. 寻找窗中最大的数字（最大值滤波）
// 题目：例如[−2,1,−3,4,−1,2,1,−5,4]，滑窗大小为3，那么输出应该是[1,4,4,4,2,2,4]

namespace v1 {
class soultion {
public:
    vector<int> process(vector<int>& nums) {
        int count = nums.size() - 2;
        vector<int> ret;

        for (int i = 0; i < count; i++) {
            int windows = 0;
            int windows_max = nums[i];
            while (windows < 3) {
                windows_max = max(nums[i + windows], windows_max);
                windows++;
            }
            ret.push_back(windows_max);
        }
        return ret;
    }
};
}

namespace v2 {
    class soultion {
    public:
        vector<int> process(vector<int>& nums, int windowsLen) {
            int count = nums.size() - windowsLen + 1;
            vector<int> ret(count);
    
            for (int i = 0; i < count; i++) {
                int windows = 0;
                int windows_max = nums[i];
                while (windows < windowsLen) {
                    windows_max = max(nums[i + windows], windows_max);
                    windows++;
                }
                // ret.push_back(windows_max);
                ret[i] = windows_max;
            }
            return ret;
        }
    };
}

int main() {
    v2::soultion s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> ret = s.process(nums, 3);
    for (auto data : ret) {
        printf("%d\t", data);
    }
    printf("\n");
    return 0;
}