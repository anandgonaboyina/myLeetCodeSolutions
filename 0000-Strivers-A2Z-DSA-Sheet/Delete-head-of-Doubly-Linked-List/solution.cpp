/*
Definition of singly linked list:
class ListNode{
  
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/
class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if(head == nullptr)
            return nullptr;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};

/*
doubley linkedlist with prev and next as node pointers
class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if(head == nullptr)
            return nullptr;
        ListNode* temp = head;
        head = head->next;

// # here we have to check if only one node there head is pointing to nullptr
// # so head->prev is going to give segmentation error

        if(head != nullptr)           
        head->prev = nullptr;
        delete temp;
        return head;
    }
};
*/

// clean code 
/*

class Solution {
public:
    ListNode *deleteHead(ListNode *&head) {
        if(!head) return nullptr;
        ListNode* temp = head;
        head = head->next;
        if(head)
            head->prev = nullptr;
        delete temp;
        return head;
    }
};
*/
