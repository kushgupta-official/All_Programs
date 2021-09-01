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
        if (!head)
            return NULL;
        Node *ite=head;
        while(ite!=NULL){
            Node *newNode=new Node(ite->val);
            newNode->next=ite->next;
            ite->next=newNode;
            ite=ite->next->next;
        }
        ite=head;
        while(ite!=NULL){
            if (ite->random!=NULL)
                ite->next->random=ite->random->next;
            ite=ite->next->next;
        }
        ite=head;
        Node *dummy=new Node(0);
        Node *toReturn =head->next;
        dummy->next=head;
        ite=head;
        while(ite!=NULL){
            dummy=ite->next;
            ite->next=dummy->next;
            if (ite->next!=NULL)
                dummy->next=ite->next->next;
            ite=ite->next;
        }
        return toReturn;
    }
};