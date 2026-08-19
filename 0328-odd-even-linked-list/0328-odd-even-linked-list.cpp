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

//optimal solution beats 100%  TC is N and SC is 1
//working logic is linking the odd and even nodes separately and attaching the first evenhead node to last odd->next of the odd linked nodes
/*
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
*/
//revision 1

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummyEven(0);
        ListNode dummyOdd(0);
        ListNode* ptr = head;
        ListNode* optr = &dummyOdd;
        ListNode* eptr = &dummyEven;
        int n =1;
        while(ptr)
        {
            if(n%2==1)
                {
                    optr->next = ptr;
                    optr = optr->next;
                }
            else
                {
                    eptr->next = ptr;
                    eptr = eptr->next;
                }
            ptr = ptr->next;
            n++;
        }
        optr->next = dummyEven.next;
        eptr->next = nullptr;
        return dummyOdd.next;
    }
};
