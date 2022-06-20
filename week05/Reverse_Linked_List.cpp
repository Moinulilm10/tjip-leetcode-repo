#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;
        auto curr = head;
        ListNode *prev = NULL;
        while (curr)
        {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// time complexity
// O(n) here n is number of element in linked list
