/*
 * @lc app=leetcode.cn id=1447 lang=cpp
 *
 * [1447] 最简分数
 */

// @lc code=start
class Solution
{
public:
    // string simplfiedDivision(int x, int y)
    // {
    //     string ans;
    //     if (y % x == 0)
    //     {
    //         ans = "1/" + to_string(y / x);
    //     }
    //     else
    //     {
    //         int a = x, b = y, c;
    //         while (a % b != 0)
    //         {
    //             c = a % b;
    //             a = b;
    //             b = c;
    //         }
    //         ans = to_string(x / c) + "/" + to_string(y / c);
    //     }
    //     return ans;
    // }

    // vector<string> simplifiedFractions(int n)
    // {
    //     vector<string> ans = {};
    //     unordered_map<string, int> cnt;
    //     for (int i = 2; i <= n; ++i)
    //     {
    //         for (int j = 1; j < i; ++j)
    //         {
    //             string temp = simplfiedDivision(j, i);
    //             cnt[temp] += 1;
    //             if (cnt[temp] == 1)
    //             {
    //                 ans.push_back(temp);
    //                 // ans.emplace_back(",");
    //             }
    //         }
    //     }
    //     return ans;
    // }
    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        for (int denominator = 2; denominator <= n; ++denominator)
        {
            for (int numerator = 1; numerator < denominator; ++numerator)
            {
                if (__gcd(numerator, denominator) == 1)
                {
                    ans.emplace_back(to_string(numerator) + "/" + to_string(denominator));
                }
            }
        }
        return ans;
    }
};
// @lc code=end
