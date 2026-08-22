/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/
//LeetCode 369: Plus One Linked List => Premium problem locked
/*
you have two standard ways to solve this:
Option 1: Reverse, Add, Reverse  => Tc is N and SC is 1 but not one pass
Option 2: The Rightmost Non-9 (More elegant, One Pass) => Tc is N and SC is 1
*/
//option 1: Reverse, Add, Reverse
/*
class Solution {
public:
    ListNode* reverseLL(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode *addOne(ListNode *head) {
        if(!head) return head;
        int carry = 1;
        head = reverseLL(head);
        ListNode* ptr = head;
        while(ptr)
        {
            if(ptr->val <9)
            {
                ptr->val +=1;
                carry = 0;
                break;
            }
            ptr->val = 0;
            ptr = ptr->next;
        }
            head = reverseLL(head);
        if(carry==1)
        {   
            ListNode* temp = new ListNode(1, head);
            head = temp;
        }
        return head;
    }
};
*/
/*
=========================================
REVISION NOTES
=========================================
1. Complexity:
   - Time: O(N). We traverse the list exactly 3 times (Reverse, Traverse for addition, Reverse back). 3N is O(N).
   - Space: O(1). We modify the nodes in place without extra data structures.

2. The Edge Case (999 -> 1000):
   - If the number consists entirely of 9s, the loop will turn them all into 0s, 
     and the carry will remain 1. 
   - We handle this AFTER reversing the list back by creating a new head node 
     with value 1 and linking it to the rest of the list.

3. Two-Argument Constructor:
   - `new ListNode(1, head)` is a fast way to create a node with value 1 
     whose 'next' pointer immediately points to 'head'.
*/

//option 2: The Rightmost Non-9 (More elegant, One Pass)
class Solution {
public:
    ListNode* addOne(ListNode* head)
    {
        if(!head) return head;
        if(head->val <9 && !head->next)
        {
            head->val +=1;
            return head;
        }
        ListNode* ptr = head;
        ListNode* lastNot9 = nullptr;
        while(ptr)
        {
            if(ptr->val !=9)
                lastNot9 = ptr;
            ptr = ptr->next;
        }
        if(lastNot9)
        {
            lastNot9->val += 1;
            ptr = lastNot9->next;
        }
        else
        {
            ListNode* temp = new ListNode(1, head);
            head = temp;
            ptr = temp->next;
        }
        while(ptr)
        {
            ptr->val =0;
            ptr = ptr->next;
        }
        return head;
    }
};

/*
=========================================
REVISION NOTES: ADD ONE TO LINKED LIST
=========================================
1. The Core Strategy (One-Pass):
   - Traverse to find the RIGHTMOST node that is NOT a 9 (`lastNot9`).
   - Increment `lastNot9`.
   - Flip all nodes to the right of `lastNot9` to 0.

2. TRAP 1: Pointer Arithmetic vs. Value Modification
   - MISTAKE: Writing `lastNot9 += 1;`
   - WHY IT FAILS: This shifts the pointer to a random memory address, causing a segfault. 
   - FIX: Always explicitly modify the integer: `lastNot9->val += 1;`

3. TRAP 2: The "All 9s" Edge Case (e.g., 999 -> 1000)
   - If the list is entirely 9s, `lastNot9` will remain `nullptr`.
   - FIX: You must create a new head node with value 1: `new ListNode(1, head);`

4. TRAP 3: Forgetting to Reset the Pointer for the Zero-Flip
   - MISTAKE: In the "All 9s" case, creating the new head but forgetting to reset `ptr`. 
   - WHY IT FAILS: `ptr` is still `nullptr` from the first loop, so the final loop is skipped and 999 becomes 1999 instead of 1000.
   - FIX: Inside the `else` block, explicitly set `ptr = temp->next;` so the final loop can turn the 9s into 0s.
*/