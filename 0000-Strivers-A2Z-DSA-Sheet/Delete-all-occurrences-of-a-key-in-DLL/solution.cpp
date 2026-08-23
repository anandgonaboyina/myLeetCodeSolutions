/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/
//optimal solution 
// O(N) time, and uses O(1) space
class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode* curr = head;
        while(curr)
        {
            if(curr->val == target)
            {
                ListNode* nxt = curr->next;
                if(curr->prev)
                    curr->prev->next = curr->next;
                else
                    head = curr->next;
                if(curr->next)
                    curr->next->prev = curr->prev;
                delete curr;
                curr = nxt;
            }
            else
                curr= curr->next;
        }
        return head;
    }
};


/*
It flawlessly handles edge cases like deleting the head, the tail, or consecutive targets.
=========================================
REVISION NOTES: DELETE ALL OCCURRENCES IN DLL
=========================================
1. The Core Strategy (In-Place Deletion):
   - Forget the dummy node. Just walk the list and rewire around the target nodes.
   - Always store `curr->next` and `curr->prev` in temporary variables before deleting `curr` so you don't lose your place.

2. TRAP 1: The Half-Wire
   - MISTAKE: Only updating `prev->next`.
   - WHY IT FAILS: It breaks the reverse traversal of the DLL.
   - FIX: Always update `nxt->prev = prv` as well.

3. TRAP 2: Deleting the Head
   - MISTAKE: Not updating the `head` pointer when the first node is a target.
   - FIX: If `prv` is null, it means `curr` is the head. Update `head = nxt;`.
*/