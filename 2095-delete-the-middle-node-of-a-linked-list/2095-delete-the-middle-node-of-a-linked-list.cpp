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
 //my brute force solution got 50% beats TC is N and Sc is 1
// got 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* ptr = head;
        while(ptr->next != slow)
        {
            ptr = ptr->next;
        }
        ListNode* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        return head;
    }
};

//optimal solution got 100% beats
/*
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next->next;  // so now the slow will sit exactly before the middle element
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
};
*/