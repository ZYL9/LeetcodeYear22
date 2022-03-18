/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() != b.size() ? a.size() < b.size() : a > b; });
        string longest;
        unordered_set<string> candidates = {""};
        for (const auto &word : words)
        {
            if (candidates.count(word.substr(0, word.size() - 1)))
            {
                candidates.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};

// @lc code=end
