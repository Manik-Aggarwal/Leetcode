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
    int getLength(ListNode* head){
        int len = 0;
        while(head !=NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    
//     ListNode* middleNode(ListNode* head) {
//         int len = getLength(head);
//         int ans = len/2;
//         ListNode* temp = head;
        
//         int count = 0;
//         while(count<ans){
//             temp = temp->next;
//             count++;
//         }
//         return temp;
//     }
    
    ListNode* getMiddle(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        
        if(head->next->next == NULL) return head->next;
        
        ListNode* onestep = head;
        ListNode* twostep = head->next;
        
        while(twostep!=NULL){
            twostep = twostep->next;
            if(twostep!=NULL) twostep = twostep->next;
            
            onestep = onestep->next;
        }
        return onestep;
    }
    
    ListNode* middleNode(ListNode* head) {
        return getMiddle(head);
    }
};