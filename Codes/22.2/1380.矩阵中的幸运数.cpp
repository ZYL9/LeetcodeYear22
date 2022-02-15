/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        size_t idx = 0;
        int t = INT_MIN;
        for (auto &&i : matrix)
        {
            auto it = min_element(i.begin(), i.end());
            if (*it > t)
            {
                idx = it - i.begin();
                t = *it;
            }
        }
        for (auto &&i : matrix)
        {
            if (i[idx] > t)
            {
                return {};
            }
        }
        return {t};
    }
};
// @lc code=end
