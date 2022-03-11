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
    bool checkPalindrome(vector<int> arr){
        int n = arr.size();
        for(int i=0, j=n-1; i<j; i++,j--){
            if(arr[i] != arr[j]) return false;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return checkPalindrome(arr);
    }
};