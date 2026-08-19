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
 //leetcode : Middle of Linked List
 //my brute force solution got 100% beats TC is N and SC is 1
 //but it is two pass
 /*
class Solution {
public:
    ListNode* middleOfLinkedList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ptr = head;
        int cnt =0;
        while(ptr)
        {
            cnt++;
            ptr = ptr->next;
        }
        ptr = head;
        for(int i=0; i<cnt/2; i++)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
};
*/
/*
an interview, the immediate follow-up question will be: "Can you find the middle in exactly one pass instead of one and a half?"
To do this, you use the Tortoise and Hare (Slow and Fast Pointers) technique.
## The Hint:  ##
Create two pointers: slow and fast. Start both at head.
Run a while loop.
Move fast forward by two steps (fast = fast->next->next).
Move slow forward by one step (slow = slow->next).
Because the fast pointer travels exactly twice as fast, by the time it hits the end of the list (nullptr), the slow pointer will be trapped exactly in the middle.
*/
// TC is N in one pass and SC is 1
class Solution {
public:
    ListNode* middleOfLinkedList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
