/*
 * @lc app=leetcode.cn id=1994 lang=cpp
 *
 * [1994] 好子集的数目
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

//动态规划
// class Solution
// {
// private:
//     static constexpr array<int, 10> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
//     static constexpr int num_max = 30;
//     static constexpr int mod = 1000000007;

// public:
//     int numberOfGoodSubsets(vector<int> &nums)
//     {
//         vector<int> freq(num_max + 1);
//         for (int num : nums)
//         {
//             ++freq[num];
//         }

//         vector<int> f(1 << primes.size());
//         f[0] = 1;
//         for (int _ = 0; _ < freq[1]; ++_)
//         {
//             f[0] = f[0] * 2 % mod;
//         }

//         for (int i = 2; i <= num_max; ++i)
//         {
//             if (!freq[i])
//             {
//                 continue;
//             }

//             // 检查 i 的每个质因数是否均不超过 1 个
//             int subset = 0, x = i;
//             bool check = true;
//             for (int j = 0; j < primes.size(); ++j)
//             {
//                 int prime = primes[j];
//                 if (x % (prime * prime) == 0)
//                 {
//                     check = false;
//                     break;
//                 }
//                 if (x % prime == 0)
//                 {
//                     subset |= (1 << j);
//                 }
//             }
//             if (!check)
//             {
//                 continue;
//             }

//             // 动态规划
//             for (int mask = (1 << primes.size()) - 1; mask > 0; --mask)
//             {
//                 if ((mask & subset) == subset)
//                 {
//                     f[mask] = (f[mask] + static_cast<long long>(f[mask ^ subset]) * freq[i]) % mod;
//                 }
//             }
//         }

//         int ans = 0;
//         for (int mask = 1, mask_max = (1 << primes.size()); mask < mask_max; ++mask)
//         {
//             ans = (ans + f[mask]) % mod;
//         }

//         return ans;
//     }
// };

//穷举
class Solution
{
public:
    int numberOfGoodSubsets(vector<int> &nums)
    {
        vector<long long> cnt(31);
        long long ans = 0, MOD = 1e9 + 7;
        for (auto num : nums)
            cnt[num]++; //首先计数

        vector<int> pos = {2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 21, 22, 26, 30};
        //从这里面选数
        vector<int> once = {17, 19, 23, 29};
        //只出现一次的最后考虑

        for (int i = 1; i < 1 << 14; i++)
        {
            if (__builtin_popcount(i) > 6)
                continue; //最多只能互斥的选六个数，2，3，5，7，11，13
            vector<int> chossen;
            for (int j = 0; j < 14; j++)
            {
                if (i >> j & 1)
                    chossen.push_back(pos[j]);
            }
            int flag = 0;
            for (auto ch : chossen)
            {
                if (cnt[ch] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            flag = 0;
            long long tmpcnt = 1;
            for (int a = 0; a < chossen.size(); a++)
            {
                for (int b = a + 1; b < chossen.size(); b++)
                {
                    if (gcd(chossen[a], chossen[b]) != 1)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                continue;
            for (auto ch : chossen)
            {
                tmpcnt *= cnt[ch];
                tmpcnt %= MOD;
            }
            ans += tmpcnt;
            ans %= MOD;
        }
        for (int i = 0; i < 4; i++)
        {
            int num = once[i];
            if (cnt[num] == 0)
                continue;
            ans = ans + ((ans + 1) * cnt[num]) % MOD;
            ans %= MOD;
        }
        //考虑1
        if (cnt[1])
        {
            long long num = cnt[1];
            while (num--)
            {
                ans = (ans * 2) % MOD;
            }
        }
        return ans;
    }
};

/*
1 1
2 2
3 3
5
6 2 * 3
7
10 2 * 5
11
13
14 2 * 7
15 3 * 5
17
19
21 3 * 7
22 2 * 11
23
26 2 * 13
29
30 2 * 3 * 5
*/

// @lc code=end
