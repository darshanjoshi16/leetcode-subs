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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ten = 0;
        ListNode* result = new ListNode(-1);
        ListNode* head = result;
            
        while(l1 != nullptr && l2 != nullptr){
            if(head->val != -1){
                head->next = new ListNode(0);
                head = head->next;
            }
            else head->val = 0;
            
            int res = l1->val + l2->val + ten;
            head->val += res % 10;
    
            ten = res / 10;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* longer = l1 == nullptr ? l2 : l1;
        
        while(longer != nullptr){
            int res = longer->val + ten;
            ten = res / 10;
            head->next = new ListNode(res % 10);
            head = head->next;
            
            longer = longer->next;
        }
        
        if(ten == 1) head->next = new ListNode(1);
        
        return result;
    }
};
