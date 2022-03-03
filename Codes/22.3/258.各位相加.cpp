/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //常规方法
    // int addDigits(int num)
    // {
    //     int res = num;
    //     while (res / 10 > 0)
    //     {
    //         int a = res / 10;
    //         int b = res % 10;
    //         res = a + b;
    //     }
    //     return res;
    // }

    //数学公式
    int addDigits(int num)
    {
        return (num - 1) % 9 + 1;
    }
};
// @lc code=end
