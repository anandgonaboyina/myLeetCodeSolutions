/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//leetcode : 141. Linked List Cycle

//my brute force solution TC is N and SC is N so getting 8% beats
/*
class Solution{
    public:
    bool hasCycle(ListNode* head)
    {
        if(!head || !head->next) return false;
        unordered_set<ListNode*> pointers;
        ListNode* ptr= head;
        while(ptr)
        {
            if(pointers.contains(ptr))
                return true;
            pointers.insert(ptr);
            ptr = ptr->next;
        }
        return false;
    }
};
*/

 // optimal solution obtained from logic of Tortoise and Hare pattern
 // got 97 % beats TC is N and SC is 1
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
           {
                slow = slow->next;
                fast = fast->next->next;
                if(slow  == fast)
                       return true;
           }

        return false;
    }
};


 //my brute force 2 discarded approach because it wont work as it goes to inifinite loop if loop there
// waste of time 
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode* ptr1 = head;
        ListNode* ptr2 = nullptr;
        while(ptr1)
           {
                ptr2 = ptr1;
                while(ptr2)
                {
                    if(ptr2 == ptr1)
                        return true;
                    ptr2 = ptr2->next;
                }
            ptr1 = ptr1->next;
           }
        return false;
    }
};
*/



