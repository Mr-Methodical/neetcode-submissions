/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // nothing to copy and we at least want one
        Node *l1 = head;
        // we want l1 to point random to point to our new node
        // and then that new node to point to the random one that l1 points to so we don't lose that info
        while (l1) {
            Node *l2 = new Node(l1->val);
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }
        // our next job is to figure out the randoms for l2
        Node *new_head = head->random;
        l1 = head;
        while (l1) {
            Node *l2 = l1->random;
            l2->random = (l2->next) ? l2->next->random : nullptr;
            l1 = l1->next;
        }
        l1 = head;
        while (l1) {
            Node *l2 = l1->random;
            l1->random = l2->next;
            l1 = l1->next;
            l2->next = (l1) ? l1->random : nullptr;
        }
        return new_head;
    }
};
