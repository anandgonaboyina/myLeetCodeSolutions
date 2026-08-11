/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//brute force approach TC is N and SC is N got 49% beats
class Solution{
    public:
    ListNode* findStartingPoint(ListNode* head)
    {
        if(!head || !head->next) return nullptr;
        unordered_set<ListNode*> nodes;
        ListNode* ptr = head;
        while(ptr)
        {
            if(nodes.contains(ptr))
                return ptr;
            nodes.insert(ptr);
            ptr = ptr->next;
        }
        return nullptr;
    }
};


 // optimal solution obtained from cycle in list 1 check Note its below this solution
 //TC is N and SC is 1 got 72 % beats
 /*
class Solution {
public:
    ListNode *findStartingPoint(ListNode *head) {
        if(!head || !head->next)    return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow == fast)
        {
            fast = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        return slow;
        }
        return nullptr;
    }
};
*/

//Notes of this approach
/*
based on Floyd's Cycle-Finding Algorithm Math (how it works):

Let:
L1 = Distance from HEAD to the START of the cycle.
L2 = Distance from START of the cycle to the COLLISION point.
C  = Total length of the cycle.

1. Distance traveled by slow = L1 + L2
2. Distance traveled by fast = L1 + L2 + n*C (fast looped 'n' times)

Since 'fast' moves 2x as fast as 'slow':
2 * (Distance of slow) = Distance of fast
2 * (L1 + L2) = L1 + L2 + n*C

Subtract (L1 + L2) from both sides:
L1 + L2 = n*C

Isolate L1:
L1 = n*C - L2

What does this mean?
- L1 is the distance from the HEAD to the cycle START.
- (n*C - L2) is the remaining distance from the COLLISION point to the cycle START.

Therefore, if Pointer 1 starts at HEAD and Pointer 2 starts at COLLISION,
and they move at the SAME speed, they will perfectly meet at the cycle START.

*/