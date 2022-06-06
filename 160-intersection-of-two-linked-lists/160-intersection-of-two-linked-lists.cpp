/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA;
        ListNode *b=headB;
        int n1=0,n2=0;
        
        while(a){
            n1++;
            a=a->next;
        }
        while(b){
            n2++;
            b=b->next;
        }
        
        a=headA;
        b=headB;
        int diff=abs(n1-n2);
        
        if(n1>n2){
            while(diff){
                a=a->next;
                diff--;
            }
        } else{
            while(diff){
                b=b->next;
                diff--;
            }
        }
        while(a && b){
            if(a==b) return a;
            a=a->next;
            b=b->next;
        }
        return nullptr;
    }
};