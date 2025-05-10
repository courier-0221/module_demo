#include <iostream>
#include <vector>
#include <algorithm>

// std::max_element 函数用于查找给定范围内的最大元素，并返回指向该元素的迭代器。
// std::distance 函数用于计算两个迭代器之间的距离。

int argmax(std::vector<int> arr) {
    auto max_it = std::max_element(arr.begin(), arr.end());
    return std::distance(arr.begin(), max_it);
}

int main() {
    std::vector<int> arr = {1, 5, 3, 7, 2};
    int max_index = argmax(arr);
    std::cout << "The index of the maximum element is: " << max_index << std::endl;
    return 0;
}