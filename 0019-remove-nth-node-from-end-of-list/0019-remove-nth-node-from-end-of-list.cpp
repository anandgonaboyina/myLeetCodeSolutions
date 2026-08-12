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

 //my brute force TC is N and Sc is 1
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(head && !head->next && n==1) return nullptr;
        int len =0, fn = 0;
        ListNode* ptr = head;
        while(ptr)
        {
            ptr = ptr->next;
            len++;
        }
        fn = len-n;  // node before that we delete
        if(fn==0)
            {
                ListNode* temp = head;
                head=head->next;
                delete temp;
                return head;
            }
        ptr =head;
        for(int i=1; i<fn; i++)
        {
            ptr = ptr->next;
        }
        ListNode* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        return head;
    }
};