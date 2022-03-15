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
private:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        if(head==NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    
public:
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }
        
        //for random pointers
        unordered_map<Node*,Node*> m;
        Node* originalnode = head;
        Node* clonenode = clonehead;
        
        while(originalnode!=NULL && clonenode!=NULL){
            m[originalnode] = clonenode;
            originalnode = originalnode->next;
            clonenode = clonenode->next;
        }
        
        originalnode = head;
        clonenode = clonehead;
        
        while(originalnode!=NULL){
            clonenode->random = m[originalnode->random];
            originalnode = originalnode->next;
            clonenode = clonenode->next;
        }
        
        return clonehead;
    }
};