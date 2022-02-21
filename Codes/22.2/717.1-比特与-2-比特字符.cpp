/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int i = 0;
        while (i < bits.size() - 1)
            i += bits[i] == 1 ? 2 : 1;
        return i == bits.size() - 1;
    }
};
// @lc code=end
