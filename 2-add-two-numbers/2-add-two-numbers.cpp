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
private:
    void insertAtTail(ListNode* &head, ListNode* &tail, int data){
        ListNode* temp = new ListNode(data);
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
    
    ListNode* add(ListNode* l1, ListNode* l2){
        ListNode* anshead = NULL;
        ListNode* anstail = NULL;
        int carry = 0;
        
        while(l1!=NULL || l2!=NULL || carry!=0){
            int val1 = 0;
            int val2 = 0;

            if(l1 != NULL) val1 = l1->val;
            if(l2 != NULL) val2 = l2->val;
            
            int sum = carry + val1 + val2;
            int digit = sum%10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        return anshead;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = add(l1,l2);
        return ans;
    }
};