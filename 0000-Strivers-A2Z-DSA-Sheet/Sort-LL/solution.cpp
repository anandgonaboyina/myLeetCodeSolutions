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
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
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
        ListNode* newHead = dummy->next;
        delete  dummy;
        return newHead;
    }
    ListNode* sortList(ListNode* head) {
        return sortLL(head);
    }
};