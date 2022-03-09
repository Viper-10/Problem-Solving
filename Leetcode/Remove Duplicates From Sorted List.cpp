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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(INT32_MIN, head); 
        
        head = dummyNode; 
        
        ListNode* i = head; 
        
        while(i != NULL && i->next != NULL){
            ListNode* temp = i->next; 
            while(temp->next && temp->next->val == i->next->val){
                temp = temp->next; 
            }
            
            if(i->next != temp){
                ListNode* freeSpace = i->next; 
                i->next = temp->next; 
                temp->next = NULL; 
                delete freeSpace; 
            }else{
                i = i->next; 
            } 
        }
        
        
        return head->next; 
    }
};