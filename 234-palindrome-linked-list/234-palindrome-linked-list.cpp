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
    //Approach 1
// private:
//     bool checkPalindrome(vector<int> arr){
//         int n = arr.size();
//         for(int i=0, j=n-1; i<j; i++,j--){
//             if(arr[i] != arr[j]) return false;
//         }
//         return true;
//     }
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode* temp = head;
//         vector<int> arr;
//         while(temp){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         return checkPalindrome(arr);
//     }
    
//Approach 2
    private:
        ListNode* getMid(ListNode* head){
            ListNode* slow = head;
            ListNode*fast = head->next;
            
            while(fast!=NULL && fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    
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
    
    public:
        bool isPalindrome(ListNode* head) {
            if(head == NULL || head->next == NULL) return true;
            ListNode* mid = getMid(head);
            
            ListNode* temp = mid->next;
            
            mid->next = reverse(temp);
            
            ListNode* h1 = head;
            ListNode* h2 = mid->next;
            while(h2){
                if(h1->val != h2->val) return false;
                h1 = h1->next;
                h2 = h2->next;
            }
            
            // making LL as it was
            temp = mid->next;
            mid->next = reverse(temp);
            
            return true;
        }
};