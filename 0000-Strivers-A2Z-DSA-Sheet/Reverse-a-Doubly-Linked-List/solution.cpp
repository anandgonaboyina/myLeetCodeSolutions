/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/
//my brute force solution TC is N and SC is 1
class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* left = head;
        ListNode* right = head;
        while(right->next)
        {
            right = right->next;
        }
        while(left < right)
        {
            int temp = left->data;
            left->data = right->data;
            right->data = temp;
            left = left->next;
            right = right->prev;
        }
        return head;
    }
};