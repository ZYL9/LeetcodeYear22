/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        bool neg = num < 0;
        num = abs(num);
        string dig;
        while (num > 0)
        {
            dig.push_back(num % 7 + '0');
            num /= 7;
        }
        if (neg)
            dig.push_back('-');
        reverse(dig.begin(), dig.end());
        return dig;
    }
};
// @lc code=end
