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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* ans = ret;
        int c = 0;
        while(l1 && l2){
            ans->next = new ListNode((l1->val + l2->val + c) % 10);
            c = (l1->val + l2->val + c) / 10;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            ans->next = new ListNode((l1->val + c) % 10);
            c = (l1->val + c) / 10;
            l1 = l1->next;
            ans = ans->next;
        }
        while(l2) {
            ans->next = new ListNode((l2->val + c) % 10);
            c = (l2->val + c) / 10;
            l2 = l2->next;
            ans = ans->next;
        }
        if(c) ans->next = new ListNode(c);
        return ret->next;
    }
};