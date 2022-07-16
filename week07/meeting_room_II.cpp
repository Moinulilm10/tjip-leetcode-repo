#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        map<int, int> status;
        for (auto interval : intervals)
        {
            status[interval[0]]++;
            status[interval[1]]--;
        }
        int curRoom = 0, minRoom = 0;
        for (auto stat : status)
        {
            curRoom += stat.second;
            minRoom = max(minRoom, curRoom);
        }
        return minRoom;
    }
};

// tc: O(logN)
// space: O(n)