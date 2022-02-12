/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// private:
//     int m, n;
//     vector<vector<bool>> vis;

// public:
//     static constexpr int dirs[4][2] = {
//         {1, 0}, {0, 1}, {0, -1}, {-1, 0}};

//     void dfs(const vector<vector<int>> &grid, int x, int y)
//     {
//         if (x < 0 || x >= m || y < 0 || y > n || grid[x][y] == 0 || vis[x][y])
//             return;
//         vis[x][y] = true;
//         for (auto &dir : dirs)
//             dfs(grid, x + dir[0], y + dir[1]);
//     }
//     int numEnclaves(vector<vector<int>> &grid)
//     {
//         this->m = grid.size();
//         this->n = grid[0].size();
//         this->vis = vector<vector<bool>>(m, vector<bool>(n, false));

//         for (int i = 0; i < m; i++)
//         {
//             dfs(grid, i, 0);
//             dfs(grid, i, n - 1);
//         }
//         for (int j = 1; j < n - 1; j++)
//         {
//             dfs(grid, 0, j);
//             dfs(grid, m - 1, j);
//         }
//         int ans = 0;
//         for (int i = 1; i < m - 1; i++)
//         {
//             for (int j = 1; j < n - 1; j++)
//             {
//                 if (grid[i][j] == 1 && !vis[i][j])
//                 {
//                     ans += 1;
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution
{
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int numEnclaves(vector<vector<int>> &grid)
    {
        this->m = grid.size();
        this->n = grid[0].size();
        this->visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 1; j < n - 1; j++)
        {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        int enclaves = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    enclaves++;
                }
            }
        }
        return enclaves;
    }

    void dfs(const vector<vector<int>> &grid, int row, int col)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0 || visited[row][col])
        {
            return;
        }
        visited[row][col] = true;
        for (auto &dir : dirs)
        {
            dfs(grid, row + dir[0], col + dir[1]);
        }
    }

private:
    int m, n;
    vector<vector<bool>> visited;
};

// @lc code=end
