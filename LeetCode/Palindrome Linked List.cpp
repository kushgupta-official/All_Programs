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
    ListNode* reverseList(ListNode *curr){
        ListNode *pre=NULL,*nex=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nex;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if (!head or !head->next)
            return head;
        ListNode *slow=head,*fast=head;
        // ListNode *mid;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // mid=slow;
        slow->next=reverseList(slow->next);
        fast=slow->next;
        slow=head;
        while(fast!=NULL){
            if (fast->val!=slow->val)
                return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
        // ListNode *pre=mid,*curr=mid->next;
        
    }
};