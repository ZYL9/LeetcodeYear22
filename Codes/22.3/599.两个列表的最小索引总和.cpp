/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> cnt;
        vector<string> res;
        for (int i = 0; i < list1.size(); i++)
        {
            cnt[list1[i]] = i;
        }
        int indexSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++)
        {
            if (cnt.count(list2[i]) > 0)
            {
                int j = cnt[list2[i]];
                if (i + j < indexSum)
                {
                    res.clear();
                    res.push_back(list2[i]);
                    indexSum = i + j;
                }
                else if (i + j == indexSum)
                {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
