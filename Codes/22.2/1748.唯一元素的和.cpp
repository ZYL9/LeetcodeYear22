/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //两次遍历
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int num : nums)
        {
            cnt[num] += 1;
            ans += num;
        }
        for (auto &[i, j] : cnt)
        {
            if (j != 1)
                ans -= i * j;
        }
        return ans;
    }
    //一次遍历
    int sumOfUnique(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> state;
        for (int num : nums)
        {
            if (state[num] == 0)
            {
                ans += num;
                state[num] = 1;
            }
            else if (state[num] == 1)
            {
                ans -= num;
                state[num] = 2;
            }
        }
        return ans;
    }
};
// @lc code=end
