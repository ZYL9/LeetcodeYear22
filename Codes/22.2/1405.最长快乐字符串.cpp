/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string res;
        vector<pair<int, char>> cnt = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true)
        {
            sort(cnt.begin(), cnt.end(), [](const pair<int, char> &p1, const pair<int, char> &p2)
                 { return p1.first > p2.first; });
            bool hasNext = false;
            for (auto &[freq, ch] : cnt)
            {
                int m = res.size();
                if (freq <= 0)
                {
                    break;
                }
                if (m >= 2 && res[m - 2] == ch && res[m - 1] == ch)
                {
                    continue;
                }
                hasNext = true;
                res.push_back(ch);
                freq -= 1;
                break;
            }
            if (!hasNext)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
