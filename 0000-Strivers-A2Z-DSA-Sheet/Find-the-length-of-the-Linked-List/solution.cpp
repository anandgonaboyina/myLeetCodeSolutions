//iterative approach  
//TC is N and SC is 1 as len and ptr are fixed size not depend on input list
/*
class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* ptr = head;
        int len =0;
        while(ptr != nullptr)
            {
                len++;
                ptr = ptr->next;
            }
        return len;
    }
};
*/
/*
// recursive approach TC is N and Sc is N as stack of N functions
class Solution{
    public:
    int getLength(ListNode* head)
    {
        if(head == nullptr) 
            return 0;
        return 1 + getLength(head->next);
    }
};
*/
// optimizing the Sc for recursive method to SC as 1
/*
Currently, above recursive code performs addition (1 + getLength(...)) after the recursive call returns. This forces the system to keep stack frames open.By passing an accumulator variable to keep track of the count as you go down the list, the compiler can optimize the code to use \(O(1)\) space (Tail Call Optimization / TCO
*/
class Solution 
{
    int getLengthTail(ListNode* head, int acc)
    {
        if(head == nullptr) return acc;
        return getLengthTail(head->next, acc+1);
    }
    public :
    int getLength(ListNode* head)
    {
        return getLengthTail(head, 0);
    }
};