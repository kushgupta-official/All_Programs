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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL or head->next==NULL)
            return head;
        int len=0;
        ListNode *curr=head;
        while(curr->next!=NULL){
            len++;
            curr=curr->next;
        }
        len++;
        curr->next=head;
        curr=curr->next;
        int rot=k%len;
        for (int i=1;i<len-rot;i++){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};