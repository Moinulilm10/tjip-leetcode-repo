#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkMirror(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 && !node2)
        {
            return true;
        }
        if (!node1 || !node2)
        {
            return false;
        }
        if (node1->val == node2->val && checkMirror(node1->left, node2->right) && checkMirror(node1->right, node2->left))
        {
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        if (checkMirror(root->left, root->right))
        {
            return true;
        }
        return false;
    }
};