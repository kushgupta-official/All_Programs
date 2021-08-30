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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1){
            return l2;
        }
        else if (!l2){
            return l1;
        }
        ListNode *mnHead,*mxHead,*res;
        if (l1->val < l2->val){
            res=l1;
            mnHead=l1;
            mxHead=l2;
        }
        else{
            res=l2;
            mnHead=l2;
            mxHead=l1;
        }
        ListNode *temp;
        while(mnHead!=NULL and mxHead!=NULL){
            temp=mnHead;
            mnHead=mnHead->next;
            if (mnHead!=NULL and mxHead->val < mnHead->val){
                temp->next=mxHead;
                swap(mnHead,mxHead);
            }
        }
        if (l2!=NULL){
            temp->next=mxHead;
        }
        return res;
    }
};