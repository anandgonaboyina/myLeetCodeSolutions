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

/*
=========================================
REVISION NOTES: ADD TWO NUMBERS
=========================================
1. The Core Strategy (Single Loop):
   - Always use `while(p1 || p2 || carry)` when adding numbers. 
   - This single condition handles everything: lists of different lengths, 
     and the leftover carry at the very end (e.g., 99 + 1 = 100).

2. TRAP: Appending Remaining Nodes Directly
   - MISTAKE: Stopping the loop when one list ends and just attaching the rest of the other list.
   - WHY IT FAILS: If there is a carry, it needs to ripple through the rest of the longer list. 
     Attaching directly ignores this ripple effect.

3. Complexity:
   - Time: O(max(M, N)), where M and N are the lengths of l1 and l2.
   - Space: O(max(M, N)), as we create a new list to store the result.
*/