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
ListNode* isreverse(ListNode* head){
    ListNode* prev=NULL;
    while(head){
        ListNode* next=head->next;
        head->next=prev;

        prev=head;
        head=next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(!head||head->next==NULL) return true;
        // ListNode* temp;
        // temp=isreverse(head);
        // return head==temp;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
                    }
                    ListNode* second=isreverse(slow);
                    ListNode* first =head;
                    while(second){
                        if(first->val!=second->val) return false;
                        first=first->next;
                        second=second->next;
                    }
                    return true;
    }
};