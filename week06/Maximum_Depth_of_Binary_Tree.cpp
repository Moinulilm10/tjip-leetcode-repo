#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int l_tree = maxDepth(root->left);
        int r_tree = maxDepth(root->right);

        if (l_tree > r_tree)
            return (l_tree + 1);
        else
            return (r_tree + 1);
    }
};

// Tc: O(n) here n is number of node