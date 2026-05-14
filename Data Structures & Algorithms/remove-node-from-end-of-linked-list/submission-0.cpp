/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we don't have starting point so let's use a dummy node
        // what if we used a double pointer approach
        // oh let's go with double pointer and dummy node approach
        ListNode dummy = ListNode(0, head); 
        ListNode *curr = &dummy;
        ListNode *fast = head;
        for (int i = 0; i < n; ++i) fast = fast->next;
        while (fast) {
            fast = fast->next;
            curr = curr->next;
        }
        // now curr is right before the one we want to skip over:
        curr->next = curr->next->next;
        return dummy.next;
    }
};
