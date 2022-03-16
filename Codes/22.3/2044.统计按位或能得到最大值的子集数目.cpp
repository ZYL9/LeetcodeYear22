/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        this->nums = nums;
        this->maxOr = 0;
        this->cnt = 0;
        dfs(0, 0);
        return cnt;
    }

    void dfs(int pos, int orVal)
    {
        if (pos == nums.size())
        {
            if (orVal > maxOr)
            {
                maxOr = orVal;
                cnt = 1;
            }
            else if (orVal == maxOr)
            {
                cnt++;
            }
            return;
        }
        dfs(pos + 1, orVal | nums[pos]);
        dfs(pos + 1, orVal);
    }

private:
    vector<int> nums;
    int maxOr, cnt;
};
// @lc code=end
