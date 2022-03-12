/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> m; 
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL; 
        
        Node* temp = head, *newList = new Node(head->val); 
        
        Node* storeNewHead = newList;
        m[head] = newList; 
        
        while(temp->next){
            newList->next = new Node(temp->next->val);
            m[temp->next] = newList->next;
            temp = temp->next; 
            newList = newList->next; 
        }
        m[NULL] = NULL; 
        newList = storeNewHead;      
        
        temp = head; 
        while(temp){
            newList->random = m[temp->random];
            temp = temp->next; 
            newList = newList->next; 
        }
        
        return storeNewHead;
    }
};