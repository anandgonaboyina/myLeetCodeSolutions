/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/


/*
## Note
 Pointer Comparison
we cannot use < or > to compare node pointers in a linked list. Linked list nodes are dynamically allocated in the heap, meaning they are scattered randomly in memory. right could actually have a lower memory address than left, causing your loop to run forever or access invalid memory.
####################
To stop the loop when pointers cross in a DLL, you must check for exact matches: 
while (left != right && left->prev != right).
*/
//my brute force solution TC is N and SC is 1  but its not allowed a way to do
//The Interview Trap:
/*
Swapping data inside nodes is generally considered a red flag in interviews. In real-world systems, the data payload of a node might be a massive object. Swapping heavy objects is incredibly slow. Instead, you are expected to leave the data alone and swap the pointers.
*/
/*
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
        while(left != right && left->prev != right)  // here not like left < right as pointers are addresses not values 
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
*/
//swaping the pointers my apporach
/*
class Solution{
    public:
    ListNode* reverseDLL(ListNode* head)
    {
        if(!head || !head->prev) return head;
        ListNode* left =head;
        ListNode* right =head;
        while(right->next)
        {
            right = right->next;
        }
        head = right;
        while(left != right && left->prev != right)
        {
            ListNode* tempL = left;
            ListNode* tempR = right;
            left = right;
            right = tempL;
            left->prev = tempL->prev;
            left->next = tempL->next;
            right->prev = tempR->prev;
            right->next = tempR->next;
        }
        return head;
    }
};
*/
// better approach to swap the prev and next pointer and pointing to the second last prev node give the tail of the linkedlist which is the head to return
//TC is O(N) with SC O(1).
class Solution{
    public:
    ListNode* reverseDLL(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* temp = nullptr;
        while(curr != nullptr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }
        return temp->prev;
    }
};


// revision 1
//in place replacement but reductant head never use this way
class Solution{
    public:
    ListNode* reverseDLL(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* ptr = head;
        while(ptr)
        {
            ListNode* prev = ptr->prev;
            ptr->prev = ptr->next;
            ptr->next = prev;
            if(ptr->prev)
                head = ptr;
            ptr = ptr->prev;
        }
        return head;
    }
};

//above have Redundant Assignment: Moving head = ptr; inside the loop updates the head variable on every single iteration

class Solution{
    public:
    ListNode* reverseDLL(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr)
        {
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
            head = prev->prev;  // here we have to give the newhead that is in prev of prev
        return head;
    }
};










