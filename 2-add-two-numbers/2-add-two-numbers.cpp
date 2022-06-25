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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=nullptr;
        ListNode *ans=nullptr;
        int carry=0;
        while(l1||l2||carry){
            int sum=carry;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            carry=sum/10;
            sum%=10;
            if(temp1==nullptr){
                temp1=new ListNode(sum);
                ans=temp1;
            }else{
                ListNode *temp2=new ListNode(sum);
                temp1->next=temp2;
                temp1=temp1->next;
            }
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;

        }
        return ans;
    }
};