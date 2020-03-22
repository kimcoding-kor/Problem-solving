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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* a = head, *b = head->next;
        while(a != b){
            if(!b || !b->next) return false;
            a = a->next;
            b = b->next->next;
        }
        return true;
    }
};