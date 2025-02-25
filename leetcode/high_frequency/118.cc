#include <vector>
#include <iostream>

/*
递推公式：
    每一行的数字是由上一行的相邻两个数字的和得到的。
    例如，第 i 行的第 j 个元素 triangle[i][j] 的值可以通过 triangle[i-1][j-1] + triangle[i-1][j] 计算得到。
初始化： 第一行只有一个 1。
迭代过程：
    每生成一行，从前到后填充 1 和上一行的元素相加得到当前行的值。
终止条件： 生成的杨辉三角的行数为 numRows。
*/

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        // 处理每一行
        for (int i = 0; i < numRows; ++i) {
            std::vector<int> row(i + 1, 1); // 每一行初始化为全 1

            // 计算该行中间的元素（除了两侧的 1）
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // 将当前行加入到杨辉三角中
            triangle.push_back(row);
        }

        return triangle;
    }
};

int main() {
    Solution solution;
    int numRows = 5;
    auto triangle = solution.generate(numRows);

    // 打印结果
    for (const auto& row : triangle) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
