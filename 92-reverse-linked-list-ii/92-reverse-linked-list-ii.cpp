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
    ListNode *reverse(ListNode *start,ListNode *end){
        ListNode *curr=start,*pre=nullptr, *next=start;
        while(curr!=end){
            next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(!head || !(head->next) || m==n) return head;
    ListNode *mcurr=head, *mpre=nullptr, *ncurr=head, *npre=nullptr;
    while(m-1){
        mpre=mcurr;
        mcurr=mcurr->next;
        m--;
    }
    while(n-1){
        npre=ncurr;
        ncurr=ncurr->next;
        n--;
    }
    npre=ncurr;
    ncurr=ncurr->next;
    if(mpre) mpre->next=reverse(mcurr,ncurr);
    else head=reverse(mcurr,ncurr);
    
    mcurr->next=ncurr;
    return head;

    }
};

