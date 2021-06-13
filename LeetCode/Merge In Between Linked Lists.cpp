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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head=list1;
        for (int i=1;i<a;i++){
            list1=list1->next;
        }
        ListNode *fi=list1;
        for (int i=a;i<=b;i++){
            list1=list1->next;
        }
        ListNode *se=list1->next;
        ListNode *head2=list2;
        while(list2->next!=NULL){
            list2=list2->next;
        }
        fi->next=head2;
        list2->next=se;
        return head;
    }
};