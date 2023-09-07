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
        ListNode *beforeLeft, *pright;
        ListNode *curr = head;

        while(curr){
            if(left==2)beforeLeft = curr;
            if(right==1)pright = curr;
            curr = curr->next;
            left--;
            right--;
        }
        ListNode *prev = pright->next,*next; curr = beforeLeft ? beforeLeft -> next:head;
        pright->next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(!beforeLeft) return pright;
        beforeLeft->next = pright;
        return head;

    }
};