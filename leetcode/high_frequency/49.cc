#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 字母异位词分组
// 思路:
//    使用hash表来解决，key为排序后的str
// 先对str内容进行排序，然后当作key值，将有同样key顺序的str加入到key对应的hash种

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        vector<vector<string>> ret;
        for (string str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            hashmap[key].push_back(str);
        }

        for (unordered_map<string, vector<string>>::iterator it = hashmap.begin(); it != hashmap.end(); it++)
        {
            ret.push_back(it->second);
        }
        return ret;
    }
};

void print_arr(vector<vector<string>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            printf("%s\t", arr[i][j].c_str());
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    Solution s;
    vector<string> str1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret1 = s.groupAnagrams(str1);
    print_arr(ret1);

    return 0;
}