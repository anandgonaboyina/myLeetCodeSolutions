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

//No leetcode problem is available

*/
//my brute force solution
//Tc is N and SC is 1 but replacing the data is not allowed in linkedlist
/*
class Solution {
    public:
        ListNode* sortList(ListNode* head) 
    {
           ListNode* ptr = head;
           int zeros=0,ones=0;
           while(ptr)
           {
            if(ptr->data==0)
                zeros++;
            else if(ptr->data == 1)
                ones++;
            ptr->data = 2;
            ptr = ptr->next;
           }

        ptr = head;
        while(zeros != 0)
        {
            ptr->data = 0;
            ptr=ptr->next;
            zeros--;
        }
        while(ones !=0)
        {
            ptr->data = 1;
            ptr = ptr->next;
            ones--;
        }
        return head;
    }
};
*/
//my optimal solution
// TC is N and SC is 1
class Solution {
    public:
        ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)  return head;
            ListNode dummy0(0), dummy1(1), dummy2(2);
           ListNode* zero = &dummy0;
           ListNode* one = &dummy1;
           ListNode* two = &dummy2;
           ListNode* ptr = head;
           while(ptr)
           {
            if(ptr->data==0)
            {
                zero->next = ptr;
                zero = zero->next;
            }
            else if(ptr->data == 1)
            {
                one->next = ptr;
                one = one->next;
            }
           else
           {
                two->next = ptr;
                two = two->next;
           }
           ptr = ptr->next;
           }
           zero->next = (dummy1.next != nullptr)? dummy1.next : dummy2.next;
           one->next = dummy2.next;
           two->next = nullptr;
        return dummy0.next;
    }
};


/*
=========================================
REVISION NOTES
=========================================
1. Complexity:
   - Time: O(N) because we traverse the list exactly once.
   - Space: O(1) because we only rewire existing nodes using pointers.

2. Dummy Nodes (Stack Allocation):
   - Using stack-allocated dummy nodes (dummy0, dummy1, dummy2) makes handling 
     empty lists of 0s, 1s, or 2s incredibly easy without messy if/else checks.
   - Because they are on the stack, NO 'new' and NO 'delete' memory management is needed.

3. Object vs. Pointer Access:
   - Stack objects use the dot operator: `dummy1.next`
   - Pointers use the arrow operator: `one->next`

4. Cycle Prevention:
   - `two->next = nullptr;` is absolutely critical. If the last '2' node originally 
     pointed to a '0' or '1' in the unsorted list, failing to cut this link will 
     create an infinite loop.

5. The Ternary Merge:
   - `zero->next = (dummy1.next != nullptr) ? dummy1.next : dummy2.next;`
   - If there are no 1s in the list, the 0s must link directly to the 2s.
*/