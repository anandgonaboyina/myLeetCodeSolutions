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
 //my brute force solution got 100% beats after spending 1hr
 // this is the optimal solution TC is N and SC is 1
 //iterative solution
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// recursive solution
//TC is N and SC is N due to recursion stack goes up to n levels deep
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
            ListNode* newHead = reverseList(head->next);                              // this is going to carry back til the first node of list without changing
            head->next->next = head;                                                   // linking the next node's next back to present node
            head->next =nullptr;                                                       // present node to the nullptr think it as a LL with 2 nodes
        return newHead;
    }
};
*/

/*

//revision cnt 1
// iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
*/
//recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* nextNode = head->next;
        ListNode* newHead = reverseList(head->next);
        nextNode->next = head;
        head->next =nullptr;
        return newHead;
    }
};