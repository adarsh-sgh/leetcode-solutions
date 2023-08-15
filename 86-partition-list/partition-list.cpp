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

    ListNode* partition(ListNode* head, int x) {
        ListNode * l1 = new ListNode(-1),*l2 = new ListNode(-1);
        ListNode *l1o = l1, *l2o = l2;
        ListNode *curr = head;
        while(curr){
            if(curr->val < x){
                l1 = l1->next = curr;
            }
            else{
                l2 = l2->next = curr;
            }
            curr = curr->next;
        }
        l2->next = nullptr;
        l1->next = l2o->next;
        return l1o->next;
    }

};