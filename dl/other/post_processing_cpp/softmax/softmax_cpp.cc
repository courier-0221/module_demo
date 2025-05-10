#include <iostream>
#include <vector>
#include <cmath>

double exp(double x) {
    // 计算自然对数的底数 e
    double e = 2.71828182845904523536;
    // 计算 e 的 x 次方
    double result = 1.0;
    double term = 1.0;
    for (int i = 1; i <= 100; i++) {
        term *= x / i;
        result += term;
    }
    return result;
}

std::vector<double> softmax(std::vector<double> x) {
    std::vector<double> result;
    double sum = 0.0;
    for (int i = 0; i < x.size(); i++) {
        // sum += std::exp(x[i]);
        sum += exp(x[i]);
    }
    for (int i = 0; i < x.size(); i++) {
        result.push_back(std::exp(x[i]) / sum);
    }
    return result;
}

int main() {
    std::vector<double> x = {1.0, 2.0, 3.0};
    std::vector<double> result = softmax(x);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}