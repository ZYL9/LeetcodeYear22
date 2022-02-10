/*
 * @lc app=leetcode.cn id=2006 lang=cpp
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int num : nums)
        {
            ans += (cnt.count(num - k)) ? cnt[num - k] : 0;
            ans += (cnt.count(num + k)) ? cnt[num + k] : 0;
            cnt[num] += 1;
        }

        return ans;
    }
};
// @lc code=end
