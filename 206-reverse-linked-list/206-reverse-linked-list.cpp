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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL) return head;
        
//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* temp = NULL;
        
//         while(curr!=NULL){
//             temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;
//         }
        
//         return prev;
//     }
// };

void reverse(ListNode* &head, ListNode* curr, ListNode* prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    
    ListNode* temp = curr->next;
    reverse(head, temp, curr);
    curr->next = prev;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head,curr,prev);
        return head;
    }
};