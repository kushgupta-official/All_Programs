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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA or !headB)
            return NULL;
        ListNode *trav1=headA,*trav2=headB;
        while(trav1!=trav2){
            trav1=trav1==NULL?headB:trav1->next;
            trav2=trav2==NULL?headA:trav2->next;
        }
        return trav1;
    }
};