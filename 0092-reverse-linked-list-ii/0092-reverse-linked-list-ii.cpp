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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || right==left){
            return head;
        }
        ListNode*prev = NULL;
        ListNode*curr = head;

        for(int i= 1; i<left; i++){
            prev=curr;
            curr=curr->next;
        }
        ListNode*back =prev;
        ListNode*tail = curr;

        for(int i=0; i<=right-left; i++){

            ListNode*next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        if(back!=NULL)
            back->next=prev;
        else
        head=prev;
        tail->next =curr;

        return head;
    }
};