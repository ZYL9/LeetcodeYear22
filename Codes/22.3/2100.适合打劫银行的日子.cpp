/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // vector<int> goodDaysToRobBank(vector<int> &security, int time)
    // {
    //     vector<int> ans;
    //     int rear = -1, cnt = 1;
    //     int n = security.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         int x = security[i];
    //         rear >= x ? cnt += 1 : cnt = 1;
    //         if (cnt > time)
    //             security[i] ^= (1 << 30);
    //         rear = x;
    //     }
    //     rear = -1, cnt = 0;
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         int x = security[i] & ~(1 << 30);
    //         rear >= x ? cnt += 1 : cnt = 1;
    //         if (cnt > time && (security[i] >> 30))
    //             ans.push_back(i);
    //         rear = x;
    //     }
    //     return ans;
    // }
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {

        int rear = -1, cnt = 1;
        int n = security.size();
        vector<int> ans;
        vector<int> mk(n, 0);
        for (int i = 0; i < n; i++)
        {
            int x = security[i];
            rear >= x ? cnt += 1 : cnt = 1;
            if (cnt > time)
                mk[i] = 1;
            rear = x;
        }
        rear = -1, cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = security[i];
            rear >= x ? cnt += 1 : cnt = 1;
            if (cnt > time && mk[i] == 1)
                ans.push_back(i);
            rear = x;
        }
        return ans;
    }
};
// @lc code=end
