/*Defination of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/
// recursive way with Sc as 1 and Tc as N
class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        if(head->nullptr) return false;
        else if(head->val == key) return true;
        return searchKey(head->next, key);
    }
};
//iterative way
/*
class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        ListNode* ptr = head;
        while(ptr !=nullptr)
        {
            if(ptr->val == key)
                return true;
        }
        return false;
    }
};
*/