#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// g++ -g -O2 -fsanitize=address -fno-omit-frame-pointer 912.cc
// 开启asan检测是否堆栈空间越界


// 对数组进行排序
// 要点：leetcode会做耗时判定，如果适用原始的快排
// 思路：
// 1.快速排序的另一种写法，使用双指针+递归实现, i、j指向pivot的后一个元素，该思路同样适用单链表的排序。 结果：超时
// 2.传统快速排序，i,j从子队列头尾向中间移动。结果：超时
// 3.传统快速排序+pivot随机化。结果：通过
// 4.pivot选中间。结果：通过

// leetcode判题用例：
// [1,50000]大小排好序的数组进行时间测试

void printf_vector(vector<int> &arr)
{
    for (int i : arr)
    {
        printf("%d\t", i);
    }
    printf("\n");
}

// 1.快排的新方式（适用单链表排序）：双指针 i, j起始时都指向同一个位置，取每一个子集合最左端节点当作基准找他的位置
namespace TimeoutVersion1
{
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        subSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void subSort(vector<int>& nums, int low, int high){
        // 选第一个元素作为pivot
        // 指针 i，指针 j 从第二个元素出发使得：
        // 指针 i 左边的都小于 pivot， 指针 i，指针 j 中间的（包括 i，j）都大于 pivot
        // j 指针比 i 跑得快，j 到达最后一个
        if (low < high) {
            int pivot = nums[low];
            int i = low + 1;
            int j = low + 1;
            while (j <= high){
                // 一开始 i,j 同步一直到第一个比 pivot 大的数出现，i 停下了
                if (nums[j] < pivot){
                    swap(nums[i], nums[j]);
                    i++;
                }
                j++;
            }
            // 最后交换 pivot 和 第 i - 1 个
            swap(nums[low], nums[i - 1]);
            // 递归调用左边右边
            subSort(nums, low, i - 2);
            subSort(nums, i, high);
        }
    }
};

void test1(void)
{
    Solution s;
    vector<int> nums = {5,1,1,2,0,0};
    vector<int> ret = s.sortArray(nums);
    printf_vector(ret);
}
} // namespace TimeoutVersion1

// 2.传统快速排序，i,j从子队列头尾向中间移动。结果：超时
// 3.传统快速排序+pivot随机化。结果：通过
// 把随机选择基准逻辑开启leetcode不会超时
namespace Version2
{
class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r) {
        //int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        //swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        //srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

void test1(void)
{
    Solution s;
    vector<int> nums = {5,1,1,2,0,0};
    vector<int> ret = s.sortArray(nums);
    printf_vector(ret);
}

}// namespace Version2

// 3. 传统方式，
namespace Version3
{
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void QuickSort(vector<int>& array, int low, int high)
    {
        if (low < high)
        {
            int local = FristLocal(array, low, high);
            QuickSort(array, low, local - 1);
            QuickSort(array, local + 1, high);
        }
    }

    int FristLocal(vector<int>& array, int low, int high)
    {
        int pivot = array[low];
        while (low < high)
        {
            // 从右向左找到比pivot小的
            while ((low < high) && (array[high] >= pivot))
            {
                high--;
            }
            swap(array[low], array[high]);

            // 从左向右找到比pivot大的
            while ((low < high) && (array[low] <= pivot))
            {
                low++;
            }
            swap(array[low], array[high]);
        }
        return low;
    }
};
void test1(void)
{
    Solution s;
    vector<int> nums = {5,1,1,2,0,0};
    vector<int> ret = s.sortArray(nums);
    printf_vector(ret);
}

}   // namespace Version3


// 4.快排不选左右端点，会超时，选中间
namespace Version4
{
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void QuickSort(vector<int>& nums, int l, int r)
    {
        if(l >= r)
            return;
        int pivot = nums[l + (r-l >> 1)], i = l - 1, j = r + 1;
        while(i < j)
        {
            do i ++; while(nums[i] < pivot);
            do j --; while(nums[j] > pivot);
            if (i < j) swap(nums[i], nums[j]);
        }
        QuickSort(nums, l, j);
        QuickSort(nums, j + 1, r);
    }
};
void test1(void)
{
    Solution s;
    vector<int> nums = {5,1,1,2,0,0};
    vector<int> ret = s.sortArray(nums);
    printf_vector(ret);
}

}   // namespace Version4




int main(void)
{
    
    //TimeoutVersion::test1();
    //Version2::test1();
    Version3::test1();
    Version4::test1();
    
    return 0;
}

