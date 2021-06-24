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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode *curr=head,*next=NULL,*prev=NULL;
        while(i<left){
            prev=curr;
            curr=curr->next;
            i++;
        }
        ListNode *temp=prev;
        ListNode *temp2=curr;
        while(i<=right){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        temp2->next=next;
        if (left==1){
            head=prev;
        }
        else{
            temp->next=prev;
        }
        return head;
    }
};