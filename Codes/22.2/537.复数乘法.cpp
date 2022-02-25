/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, int> seprate(string &num)
    {
        pair<int, int> res;
        int real = 0, img = 0;
        string::size_type sep = num.find('+');
        string s1 = num.substr(0, sep);
        string s2 = num.substr(sep + 1, num.size());
        real = atoi(s1.c_str());
        img = atoi(s2.c_str());
        res.first = real;
        res.second = img;
        return res;
    }

    string complexNumberMultiply(string &num1, string &num2)
    {
        int real1, img1, real2, img2;
        pair<int, int> tmp;
        tmp = seprate(num1);
        real1 = tmp.first;
        img1 = tmp.second;
        tmp = seprate(num2);
        real2 = tmp.first;
        img2 = tmp.second;
        int realTimes, imgTimes;
        realTimes = (real1 * real2) - (img1 * img2);
        imgTimes = (real1 * img2) + (img1 * real2);
        string res = "";
        res.append(to_string(realTimes));
        res.append("+");
        res.append(to_string(imgTimes));
        res.append("i");
        return res;
    }
};
// @lc code=end
