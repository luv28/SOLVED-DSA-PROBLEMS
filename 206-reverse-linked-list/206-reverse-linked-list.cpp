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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* temp=head;
        stack<ListNode *> s;
        while(head){
            s.push(head);
            head=head->next;
        }
        head=s.top();
        temp=head;
        s.pop();
        while(!s.empty()){
            temp->next=s.top();
            temp=temp->next;
            s.pop();
        }
        temp->next=nullptr;
        return head;
    };
};