/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //my brute force solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        while(ptr1)
        {
            ptr2 = headB;
            while(ptr2)
            {
                if(ptr1 == ptr2)
                    return ptr1;
                ptr2 = ptr2->next;
            }
            ptr1= ptr1->next;
        }
        return nullptr;
    }
};

//optimal solution