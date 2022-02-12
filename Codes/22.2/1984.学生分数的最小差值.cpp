/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - k + 1; i++)
            ans = min(ans, nums[i + k - 1] - nums[i]);
        return ans;
    }
};
// @lc code=end
