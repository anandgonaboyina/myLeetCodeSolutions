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
//LeetCode 160: Intersection of Two Linked Lists.
//my brute force solution
 //got 5% beats
 /*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        while(ptr1)
        {
            ptr2 = headB;
            while(ptr2)
            {
                if(ptr1 == ptr2)
                    return ptr1;
                ptr2 = ptr2->next;
            }
            ptr1= ptr1->next;
        }
        return nullptr;
    }
};
*/
//my better solution
//TC is M+N and SC is M+N; so got 12% beats only
/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        unordered_set<ListNode*> hashArr;
        while(ptr1 || ptr2)
        {
            if(hashArr.contains(ptr1)) return ptr1;
            if(ptr1) 
            {
                hashArr.insert(ptr1);
                ptr1= ptr1->next;
            }
            if(hashArr.contains(ptr2))
                return ptr2;
           if(ptr2)
           {
                hashArr.insert(ptr2);
                ptr2 = ptr2->next;
           }
        }
        return nullptr;
    }
};
*/
// Optimal solution TC is M+N and SC is 1
//using math to align them to point the intersect node at simultaneously
//got 40% beats
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        int l1=0, l2=0;
        while(ptr1)
        {
            l1++;
            ptr1 = ptr1->next;
        }
        while(ptr2)
        {
            l2++;
            ptr2 = ptr2->next; 
        }
        int d = abs(l1-l2);
        ptr1 = headA;
        ptr2 = headB;
        if(l1>l2)
        while(d-- != 0 && ptr1)
            ptr1 = ptr1->next;
        else
        while(d-- != 0 && ptr2)
            ptr2 = ptr2->next;
        while(ptr1 && ptr2)
        {
            if(ptr1==ptr2)
                return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return nullptr;
    }
};

//revision 1
