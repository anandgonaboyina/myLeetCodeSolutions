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
 //getting 5% beats only all the time
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
            //below is heap one slow
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