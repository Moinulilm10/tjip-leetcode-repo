#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> decreasingSubseqK;
        vector<int> snapshots;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!decreasingSubseqK.empty() && (i - k) >= decreasingSubseqK.front())
                decreasingSubseqK.pop_front();

            while (!decreasingSubseqK.empty() && nums[decreasingSubseqK.back()] < nums[i])
                decreasingSubseqK.pop_back();

            decreasingSubseqK.push_back(i);
            if (i >= k - 1)
                snapshots.push_back(nums[decreasingSubseqK.front()]);
        }
        return snapshots;
    }
};

// tc: o(n)