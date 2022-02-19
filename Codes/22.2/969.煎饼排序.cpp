/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> res;
        for (int i = arr.size(); i > 0; i--)
        {
            int index = max_element(arr.begin(), arr.begin() + i) - arr.begin();
            if (index == i - 1)
                continue;
            reverse(arr.begin(), arr.begin() + index + 1);
            reverse(arr.begin(), arr.begin() + i);
            res.push_back(index + 1);
            res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
