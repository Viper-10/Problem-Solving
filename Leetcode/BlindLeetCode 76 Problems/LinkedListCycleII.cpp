class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL; 
        
        ListNode* slow = head->next, *fast = head->next->next;
        
        while(fast && fast->next && slow != fast){
            fast = fast->next->next; 
            slow = slow->next; 
        }
        
        if(fast == NULL || fast->next == NULL){
            return NULL; 
        }
        
        while(head != slow){
            head = head->next; 
            slow = slow->next; 
        }
        

        return head; 
    }
};