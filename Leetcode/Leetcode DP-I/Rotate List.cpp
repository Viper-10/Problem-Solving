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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL; 
        
        int n = 1; 
        
        ListNode* lastNode = head; 
        
        while(lastNode->next){
            lastNode = lastNode->next; 
            n++; 
        }
        
        k %= n; 
        
        if(k == 0) return head;
        
        ListNode* temp = head; 
        
        for(int i = 0;i < n-k-1; ++i){
            temp = temp->next; 
        }
        
        ListNode* newHead = temp->next; 
        temp->next = NULL; 
        
        lastNode->next = head; 
        
        return newHead;
    }
};