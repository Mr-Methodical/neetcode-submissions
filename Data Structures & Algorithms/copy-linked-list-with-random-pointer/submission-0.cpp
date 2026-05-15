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
        // the idea is we should know which Nodes connect to which:
        unordered_map<Node *, Node *> match;
        match[nullptr] = nullptr;
        Node dummy = Node(0);
        Node *curr = &dummy;
        Node *trav = head;
        while (trav) {
            curr->next = new Node(trav->val);
            curr = curr->next;
            match[trav] = curr;
            trav = trav->next;
        }
        curr = dummy.next;
        trav = head;
        while (trav) {
            curr->random = match[trav->random];
            curr = curr->next;
            trav = trav->next;
        }
        return dummy.next;
    }
};
