/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // my brute force solution obtained from logic of Tortoise and Hare pattern
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



 //discarded approach
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(!head || !head->next)
//             return false;
//         ListNode* ptr = head;
//         ListNode* ptr2 = head;
//         while(ptr->next)
//            {
//                 while(ptr->next)
//            }
//     }
// };