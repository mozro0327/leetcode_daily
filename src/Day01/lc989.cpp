/*
 * @file: /leetcode_daily/src/Day01/lc989.cpp
 * @Author: zhuorong.mo
 * @version: v0.0.0
 * @date: 2022-04-01 22:34:25
 * @brief: 数组形式的整数加法
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int len = num.size();
        reverse(num.begin(), num.end());

        for (int i = 0; i < len; i++) {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }

        while (k > 0) {
            num.push_back(k % 10);
            k /= 10;
        }

        reverse(num.begin(), num.end());
        return num;
    }
};

class Solution2 {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int len = num.size();
        vector<int> result;

        for (int i = len - 1; i >= 0; i--) {
            int sum = num[i] + k % 10;
            k /= 10;
            if (sum > 9) {
                k++;
                sum -= 10;
            }
            result.push_back(sum);
        }
        while (k > 0) {
            result.push_back(k % 10);
            k /= 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
