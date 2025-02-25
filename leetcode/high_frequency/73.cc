#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void printf_arr(vector<vector<int>>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int, vector<int>> zeroMap;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (0 == matrix[i][j]) {
                    zeroMap[i].push_back(j);
                }
            }
        }

        // for (auto pair : zeroMap) {
        //     cout << "Key: " << pair.first << ", Value: " << endl;
        //     for (auto value : pair.second) {
        //         cout << value << " ";
        //     }
        //     cout << endl;
        // }

        for (auto pair : zeroMap) {
            // row zero
            for (int col = 0; col < matrix[0].size(); col++) {
                matrix[pair.first][col] = 0;
            }

            // col zero
            for (int i = 0; i < pair.second.size(); i++) {
                for (int row = 0; row < matrix.size(); row++) {
                    matrix[row][pair.second[i]] = 0;
                }
            }
        }
    }
};

void test1() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    sol.setZeroes(matrix);
    
    printf_arr(matrix);
}

void test2() {
    Solution sol;
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {1,4,5,2},
        {1,3,1,5}
    };

    sol.setZeroes(matrix);
    
    printf_arr(matrix);
}

int main(void) {
    test1();

    return 0;
}