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
    ListNode* reverse(ListNode* head){
            ListNode* curr = head;
            ListNode* prev = NULL;
            ListNode* nex = NULL;

            while(curr){
                nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
            }
            return prev;
        }
    
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
        
        while(l1!=NULL && l2!=NULL){
            int sum = carry + l1->val + l2->val;
            int digit = sum%10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum = carry + l1->val;
            int digit = sum%10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int sum = carry + l2->val;
            int digit = sum%10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
            l2 = l2->next;
        }
        //case when both list cam to null but carry is remaining
        while(carry!=0){
            int sum = carry;
            int digit = sum%10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
        }
        return anshead;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reverse the LL
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        
        ListNode* ans = add(l1,l2);
        return ans;
    }
};