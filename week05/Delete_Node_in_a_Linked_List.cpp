#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *deleteNode = node->next;
        node->val = deleteNode->val;
        node->next = deleteNode->next;
        delete deleteNode;
    }
};

// time complexity
// O(1)