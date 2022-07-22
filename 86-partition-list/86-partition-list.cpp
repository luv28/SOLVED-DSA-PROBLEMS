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
    ListNode* partition(ListNode* head, int B) {
        ListNode *less=new ListNode();        
        ListNode *more=new ListNode();
        ListNode *moreHead=more;
        ListNode *curr=head;
        head=less;
        while(curr){
            if(curr->val < B){
                less->next=curr;
                less=less->next;
            }
            else{
                more->next=curr;
                more=more->next;
            }
            curr=curr->next;
        }
        more->next=nullptr;
        less->next=moreHead->next;
        return head->next;
    }
};
    
    
//     if(!head || !(head->next)) return head;
//     ListNode *headB=nullptr,*headA=nullptr,*p=nullptr,*q=nullptr,*curr=head;
//     while(curr){
//         if(headA && headB) break;
//         if(curr->val<B && !headB) headB=curr;
//         else if(curr->val>=B && !headA) headA=curr;
//         curr=curr->next;
//     }
//     if(!headA || !headB) return head;
//     p=headB;
//     curr=head;
//     q=headA;
//     while(curr){
//         if(curr->val<B){
//             if(curr==p){
//                 curr=curr->next;
//                 continue;
//             }else{
//                 p->next=curr;
//                 p=p->next;
//             }
//         }else{
//             if(curr==q){
//                 curr=curr->next;
//                 continue;
//             }else{
//                 q->next=curr;
//                 q=q->next;
//             }
//         }
//         curr=curr->next;
//     }
//     p->next=headA;
//     q->next=nullptr;
//     return headB;
//     }