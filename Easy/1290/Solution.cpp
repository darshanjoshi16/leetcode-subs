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
    int getDecimalValue(ListNode* head) {
         
        //assigning the temporary node to head
        ListNode* temp = head;
        //length of binary string
        int c = 0;
        while(temp)
        {
            c++;
            temp = temp->next;
        }
        //another temporary node creation
        ListNode* temp1 = head;
        
        //logic for converting from binary to integer
        int res = 0;
        while(temp1)
        {
            res += temp1->val * pow(2,c-1);
            c--;
            temp1 = temp1->next;
        }
        return res;
        
    }
};
