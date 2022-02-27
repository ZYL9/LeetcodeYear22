/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int ans = -1;
        int premin = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > premin)
                ans = max(ans, nums[i] - premin);
            else
                premin = nums[i];
        }
        return ans;
    }
};
// @lc code=end
