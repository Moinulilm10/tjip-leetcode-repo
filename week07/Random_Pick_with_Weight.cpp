#include <bits/stdc++.h>
using namespace std;

mt19937 rd(0);

class Solution
{
public:
    vector<int> sw;

    int getRandomRange(int L, int R)
    {
        return L + (rd() % (R - L + 1));
    }

    Solution(vector<int> &w)
    {
        sw = w;
        for (int i = 1; i < sw.size(); i++)
        {
            sw[i] = sw[i - 1] + w[i];
        }
    }

    int pickIndex()
    {
        int totalSum = sw.back();
        int rnv = getRandomRange(1, totalSum);
        return lower_bound(sw.begin(), sw.end(), rnv) - sw.begin();
    }
};

// tc: O(n) n is length of weight
