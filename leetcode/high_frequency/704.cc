#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int low = 0, high = nums.size()-1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (target > nums[mid])
            {
                low = mid + 1;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else if (target == nums[mid])
            {
                return mid;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    printf("%d\n", s.search(nums, 9));
    printf("%d\n", s.search(nums, 2));

    vector<int> nums2 = {5};
    printf("%d\n", s.search(nums2, 5));
}