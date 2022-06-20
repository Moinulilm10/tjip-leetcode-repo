#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateBST(TreeNode *root, long long L_min, long long R_max)
    {
        if (!root)
            return true;
        long long v = root->val;
        if (v >= R_max || v <= L_min)
            return false;
        return validateBST(root->left, L_min, v) && validateBST(root->right, v, R_max);
    }
    bool isValidBST(TreeNode *root)
    {
        return validateBST(root, LLONG_MIN, LLONG_MAX);
    }
};