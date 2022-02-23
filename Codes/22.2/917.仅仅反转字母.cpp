/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        while (true)
        {
            while (l < r && !isalpha(s[l]))
            {
                l += 1;
            }
            while (r > l && !isalpha(s[r]))
            {
                r -= 1;
            }
            if (l >= r)
            {
                break;
            }
            swap(s[l], s[r]);
            l += 1;
            r -= 1;
        }
        return s;
    }
};
// @lc code=end
