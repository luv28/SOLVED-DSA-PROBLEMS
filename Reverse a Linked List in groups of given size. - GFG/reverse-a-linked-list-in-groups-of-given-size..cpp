// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node *reverse(node *start, node *end){
        node* a=nullptr, *b=start,*c=start;
        while(b!=end){
            c=c->next;
            b->next=a;
            a=b;
            b=c;
        }
        return a;
    }
    struct node *reverse (struct node *head, int k)
    { 
        node *start=head, *end=head, *ans=nullptr;
        int count=0;
        node *temp=nullptr;
        while(end){
            end=end->next;
            count++;
            if(count==k){
                if(!ans) ans=reverse(start,end);
                else temp->next=reverse(start,end);
                temp=start;
                start=end;
                count=0;
            }
        }
        if(start){
            temp->next=reverse(start,end);
        }
        return ans;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends