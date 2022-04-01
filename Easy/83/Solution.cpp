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

    ListNode* deleteDuplicates(ListNode* head) 
    {

        //created 2 nodes named previous and current
        ListNode *prev,*current;
        
        //assigned the value of head and null to current and previous nodes respectively
        current=head;
        prev=NULL;

        //now it will run the loop till the current node doesnt become null
        while(current!=NULL)
        {

            //it will check if previous node is not null and current node and previous node has same value
            if(prev!=NULL && current->val==prev->val)
                //it will remove the current node and give value to next one
                prev->next=current->next;
            else 
                //otherwise it will contain the current node
                prev=current;
            //traverse to the next node
            current=current->next;

        }

        return head;
}
};
