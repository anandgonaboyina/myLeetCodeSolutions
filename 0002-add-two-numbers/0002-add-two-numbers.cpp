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
 //my brute force solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* sum = &dummy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry=0;
        while(p1 || p2 || carry)
        {
            int dsum =carry;
            if(p1)
            {
                dsum += p1->val;
                p1 = p1->next;
            }
            if(p2)
            {
                dsum += p2->val;
                p2 = p2->next;
            }
            ListNode* n = new ListNode(dsum%10);
            carry = dsum/10;
            sum->next = n;
            sum = sum->next;
        }
        return dummy.next;
    }
};