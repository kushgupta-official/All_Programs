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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1=new ListNode(0);
        ListNode *ite1=l1;
        ListNode *l2=new ListNode(0);
        ListNode *ite2=l2;
        ListNode *curr=head;
        while(curr!=NULL){
            if (curr->val < x){
                ite1->next=curr;
                ite1=ite1->next;
            }
            else{
                ite2->next=curr;
                ite2=ite2->next;
            }
            curr=curr->next;
        }
        ite1->next=l2->next;
        ite2->next=NULL;
        return l1->next;
    }
};