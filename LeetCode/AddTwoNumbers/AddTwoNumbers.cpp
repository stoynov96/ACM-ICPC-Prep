/*
Not sure about this one, but I wanted to upload something in C++ too xD
Link to problem:
https://leetcode.com/problems/add-two-numbers/description/
*/

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
        ListNode* res = new ListNode(0); // dummy
        ListNode* head = res;
        short carry = 0;
        while (l1 || l2 || carry) {
            short sm = 0;
            if (l1) { sm += l1->val; l1 = l1->next; }
            if (l2) { sm += l2->val; l2 = l2->next; }
            sm += carry;
            
//             Deal with the carry
            carry = sm / 10;
            sm = sm % 10;
            
            res->next = new ListNode(sm);
            res = res->next;
        }  
        return head->next;
    }
};