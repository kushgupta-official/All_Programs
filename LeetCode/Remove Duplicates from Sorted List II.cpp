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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !head->next)
            return head;
        ListNode *res=new ListNode(0);
        ListNode *curr=res,*ite=head;
        while(ite!=NULL){
            bool flag=1;
            while(ite->next!=NULL and ite->next->val==ite->val){
                flag=0;
                ite=ite->next;
            }
            if (flag){
                curr->next=ite;
                curr=curr->next;
            }
            ite=ite->next;
        }
        curr->next=NULL;
        return res->next;
    }
};