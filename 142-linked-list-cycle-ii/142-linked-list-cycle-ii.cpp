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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        bool flag=false;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        if(!flag) return nullptr;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};