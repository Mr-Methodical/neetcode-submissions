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
    void reorderList(ListNode* head) {
        // we cut the ll in half and reverse the second part and then
        // recombine back up
        // we would like first half to be longer one if odd number
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // great now slow is the edge of the left half:
        ListNode *right_curr = slow->next;
        slow->next = nullptr;
        ListNode *right_prev = nullptr;
        while (right_curr) {
            ListNode *next = right_curr->next;
            right_curr->next = right_prev;
            right_prev = right_curr;
            right_curr = next;
        }
        // so now right_prev is other is the start of the reverse right half
        ListNode *left = head;
        ListNode *right = right_prev;
        while (left && right) {
            ListNode *next_left = left->next;
            left->next = right;
            left = next_left;
            ListNode *next_right = right->next;
            right->next = left;
            right = next_right;
        }
    }
};
