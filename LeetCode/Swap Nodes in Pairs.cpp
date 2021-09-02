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
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next)
            return head;
        ListNode* preHead=new ListNode(0);
        preHead->next=head;
        ListNode* pre=preHead,*curr=head,*ne=head->next;
        while(curr!=NULL and curr->next!=NULL){
            // cout<<curr->val<<" ";
            ne=curr->next;
            pre->next=ne;
            curr->next=ne->next;
            ne->next=curr;
            pre=curr;
            curr=curr->next;
        }
        return preHead->next;
    }
};