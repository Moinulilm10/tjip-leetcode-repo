#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *constructBst(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;
        int m = l + (r - l) / 2;
        TreeNode *curr = new TreeNode(nums[m]);
        curr->left = constructBst(nums, l, m - 1);
        curr->right = constructBst(nums, m + 1, r);
        return curr;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return constructBst(nums, 0, nums.size() - 1);
    }
};