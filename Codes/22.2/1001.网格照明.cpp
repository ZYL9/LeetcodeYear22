/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

// @lc code=start
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static constexpr int dirs[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        vector<vector<int>> lt(n, vector<int>(n, 0));
        vector<vector<int>> blowup;
        vector<int> ans;

        // light up
        for (auto &lamp : lamps)
        {
            lt[lamp[0]][lamp[1]] += 1;
            for (auto &dir : dirs)
            {
                int x = lamp[0], y = lamp[1];
                while (true)
                {
                    x += dir[0];
                    y += dir[1];
                    if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
                        break;
                    lt[x][y] += 1;
                }
            }
        }
        // query
        for (auto &query : queries)
        {
            ans.push_back(lt[query[0]][query[1]] > 0);
            // blowup list
            for (auto &dir : dirs)
            {
                int x = query[0], y = query[1];
                for (auto &lamp : lamps)
                {
                    if (lamp[0] == x && lamp[1] == y)
                    {
                        blowup.push_back({x, y});
                    }
                }
                x = query[0] + dir[0], y = query[1] + dir[1];
                for (auto &lamp : lamps)
                {
                    if (lamp[0] == x && lamp[1] == y)
                    {
                        blowup.push_back({x, y});
                    }
                }
            }
            // blowup
            for (auto &blow : blowup)
            {
                lt[blow[0]][blow[1]] -= 1;
                for (auto &dir : dirs)
                {
                    int x = blow[0], y = blow[1];
                    while (true)
                    {
                        x += dir[0];
                        y += dir[1];
                        if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
                            break;
                        lt[x][y] -= 1;
                    }
                }
            }
        }
        return ans;
    }
};
*/
class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        unordered_map<int, int> row, col, diagonal, antiDiagonal;
        auto hash_p = [](const pair<int, int> &p) -> size_t
        {
            static hash<long long> hash_ll;
            return hash_ll(p.first + (static_cast<long long>(p.second) << 32));
        };
        unordered_set<pair<int, int>, decltype(hash_p)> points(0, hash_p);
        for (auto &lamp : lamps)
        {
            if (points.count({lamp[0], lamp[1]}) > 0)
            {
                continue;
            }
            points.insert({lamp[0], lamp[1]});
            row[lamp[0]]++;
            col[lamp[1]]++;
            diagonal[lamp[0] - lamp[1]]++;
            antiDiagonal[lamp[0] + lamp[1]]++;
        }
        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int r = queries[i][0], c = queries[i][1];
            if (row.count(r) > 0 && row[r] > 0)
            {
                ret[i] = 1;
            }
            else if (col.count(c) > 0 && col[c] > 0)
            {
                ret[i] = 1;
            }
            else if (diagonal.count(r - c) > 0 && diagonal[r - c] > 0)
            {
                ret[i] = 1;
            }
            else if (antiDiagonal.count(r + c) > 0 && antiDiagonal[r + c] > 0)
            {
                ret[i] = 1;
            }
            for (int x = r - 1; x <= r + 1; x++)
            {
                for (int y = c - 1; y <= c + 1; y++)
                {
                    if (x < 0 || y < 0 || x >= n || y >= n)
                    {
                        continue;
                    }
                    auto p = points.find({x, y});
                    if (p != points.end())
                    {
                        points.erase(p);
                        row[x]--;
                        col[y]--;
                        diagonal[x - y]--;
                        antiDiagonal[x + y]--;
                    }
                }
            }
        }
        return ret;
    }
};

// @lc code=end
