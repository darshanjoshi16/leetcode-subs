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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        //if the head is not there, it wll return the head
        if(!head)
            return head;
        
        //creating the dummynode for the approach
        ListNode *dummynode=new ListNode(0);
        dummynode->next=head;
        ListNode *curr=dummynode;
        
        //logic for the deleting the elements from the linked list
        while(curr->next)
        {
            if(curr->next->val==val)
            {
                curr->next=curr->next->next;
                
            }
            else
            {
                curr=curr->next;
            }
        }
        return dummynode->next;
        
    }
};
