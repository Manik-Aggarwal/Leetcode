// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    // approach 1
    // Node* segregate(Node *head) {
    //     Node* temp = head;
    //     int count0 = 0, count1 = 0, count2 = 0;
        
    //     while(temp!=NULL){
    //         if(temp->data == 0) count0++;
    //         else if(temp->data == 1) count1++;
    //         else count2++;
            
    //         temp = temp->next;
    //     }
    //     temp = head;
    //     while(temp!=NULL){
    //         if(count0){
    //             temp->data = 0;
    //             count0--;
    //         }
    //         else if(count1){
    //             temp->data = 1;
    //             count1--;
    //         }
    //         else{
    //             temp->data = 2;
    //             count2--;
    //         }
            
    //         temp = temp->next;
    //     }
        
    //     return head;
    // }
    
    //approach 2
    Node* segregate(Node *head){
        Node* dummy0 = new Node(-1);
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);
        Node* tail0 = dummy0;
        Node* tail1 = dummy1;
        Node* tail2 = dummy2;
        Node* temp = head;
        
        while(temp!=NULL){
            if(temp->data == 0){
                tail0->next = temp;
                tail0 = temp;
            }
            else if(temp->data == 1){
                tail1->next = temp;
                tail1 = temp;
            }
            else{
                tail2->next = temp;
                tail2 = temp;
            }
            temp = temp->next;
        }
        
        //merging all LL
        if(dummy1->next != NULL) tail0->next = dummy1->next;
        else tail0->next = dummy2->next;
        tail1->next = dummy2->next;
        tail2->next = NULL;
        
        head = dummy0->next;
        
        delete dummy0;
        delete dummy1;
        delete dummy2;
        return head;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends