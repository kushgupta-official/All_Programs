/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head or !head->next)
            return NULL;
        ListNode *slow=head,*fast=head;
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(fast!=NULL and fast->next!=NULL and slow!=fast);
        if (!fast or !fast->next){
            return NULL;
        }
        // cout<<slow->val<<endl;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};