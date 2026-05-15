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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // we will do recursive approach:
        int curr_len = 0;
        ListNode *trav = head;
        while (trav && curr_len != k) {
            trav = trav->next;
            curr_len++;
        }
        if (curr_len < k) {
            return head;
        }
        // else in the other case we will need to reverse our current k nodes
        // we will need the beginning and the end because the end
        // is equal to the result of the following recursion 
        // and then we are returning the before
        ListNode *prev = nullptr;
        ListNode *curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(trav, k);
        return prev;
    }
};
