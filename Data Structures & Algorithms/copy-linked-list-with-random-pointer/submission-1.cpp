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
        // let's do the O(1) space way so we will put it after, I mean first we should create it though
        Node dummy = Node(0);
        Node *curr = &dummy;
        Node *trav = head;
        // we need to interconnect them though
        while (trav) {
            curr->next = trav; // we are at dummy so original should go first
            curr = curr->next; // now we are at the original node
            Node *trav_next = trav->next; // we want to store the original after trav
            curr->next = new Node(trav->val); // now the new node is going after trav so we get og->copy
            curr = curr->next; // now we are back at the copy
            trav = trav_next; // now this is the node that we had stored, so we are in a similar situattion as before
        }
        // ok so now it seperated nicely
        curr = &dummy;
        while (curr->next) {
            curr = curr->next;
            Node *new_node = curr->next;
            new_node->random = (curr->random) ? curr->random->next : nullptr;
            curr = new_node;
        }
        // now we got them all right for new nodes, and we just have to connect them correct back now
        curr = &dummy;
        Node *og = curr->next;
        // I guess we could also restore the original one as well actually
        while (curr->next) {
            curr->next = curr->next->next;
            og->next = og->next->next;
            og = og->next;
            curr = curr->next;
        }
        return dummy.next;
    }
};
