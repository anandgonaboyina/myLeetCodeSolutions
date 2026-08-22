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

 //optimal merge sort solution for linkedlist
 //getting 5% beats only all the time if we use heap initilization of the dummy node
 //getting 80% betas if we use stack dummy variable of node
class Solution {
public:
    ListNode* sortLL(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rightHalf = slow->next;
        slow->next = nullptr;
        ListNode* leftHead = sortLL(head);
        ListNode* rightHead = sortLL(rightHalf);
        return mergeLL(leftHead, rightHead);
    }
    ListNode* mergeLL(ListNode* l1, ListNode* l2)
    {
        //below is heap method takes time for memory allocation and delete
        /*
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        */

        //stack one is prefer as it instantly
        //Stack allocation is instantaneous, and it automatically cleans itself up, meaning no new and no delete.
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while(l1 && l2)
        {    if(l1->val <= l2->val)
            {
                
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
            curr->next = l2;
            l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1) curr->next = l1;
        else
            curr->next =l2;
        //below is heap method slow but SC is 1
        /*
        ListNode* newHead = dummy->next;
        delete  dummy;
        return newHead;
        */
        return dummy.next;  // since dummy not a pointer so it ListNode structure so dont use -> this we have to access the next of it with .
    }
    ListNode* sortList(ListNode* head) {
        return sortLL(head);
    }
};


/*
=========================================
REVISION NOTES 
=========================================
1. Complexity: 
   - Time: O(N log N) (Merge Sort is the optimal way for Linked Lists).
   - Space: O(log N) (due to the recursive call stack).

2. Heap vs. Stack Dummy Node:
   - Heap method (Slow, ~5% beats): `ListNode* dummy = new ListNode(0);`    == >  Space: O(1)
     Requires dynamic memory allocation and manual `delete dummy;`. 
     Doing this recursively O(N) times destroys execution time.
   - Stack method (Fast, ~80%+ beats): `ListNode dummy(0);` 
     Allocates memory instantly on the stack and automatically cleans it up  but  ===> Space: O(log N) 
     when the function returns.

3. Object vs. Pointer Syntax:
   - Because `dummy` is an object on the stack (not a pointer), you MUST 
     access its members using the dot operator (`dummy.next`) instead of `->`. 
   - Use `&dummy` to create a pointer (`curr`) that traverses and builds the list.
*/

//revision 1;