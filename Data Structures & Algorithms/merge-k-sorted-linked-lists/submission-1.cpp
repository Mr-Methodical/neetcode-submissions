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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b) {return a->val > b->val; };
        // so the bigger item will be pushed to bottom creating max heap
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        ListNode dummy = ListNode(0);
        ListNode *curr = &dummy;
        // we will go through every list once, and add it:
        for (int i = 0; i < lists.size(); ++i) {
            pq.push(lists[i]);
        }
        // now we keep removing the top thing until empty
        while (!pq.empty()) {
            ListNode *top_node = pq.top();
            curr->next = top_node;
            curr = curr->next;
            pq.pop(); // remove from the top
            if (top_node->next) {
                pq.push(top_node->next);
            }
        }
        return dummy.next;
    }
};
