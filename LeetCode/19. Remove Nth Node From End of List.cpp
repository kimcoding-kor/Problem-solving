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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a = head;
        ListNode* b = head;
        int cnt = 0;
        for(;b != NULL; b = b->next) cnt++;
        for(int i=1; i<cnt - n;i++)
            a = a->next;
        if(cnt == n) {
            head = head->next;
            a = NULL;
        }
        else {
            ListNode* temp = a->next;
            a->next = a->next->next;
            temp = NULL;
        }
        return head;
    }
};