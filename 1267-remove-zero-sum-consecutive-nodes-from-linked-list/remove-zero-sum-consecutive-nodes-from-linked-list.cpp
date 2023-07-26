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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode *>m;
        int psum = 0;
        ListNode *temp = new ListNode(0,head);
        m[0] = temp;
        while(head){
            psum += head->val;
            if(m.count(psum)){
                ListNode *curr = m[psum]->next;
                int tsum = psum;
                while(curr != head){
                    tsum += curr->val;
                    if(m[tsum]==curr)m.erase(tsum);
                    curr = curr->next;
                }
                m[psum]->next = head->next;
            }
            else m[psum] = head;
            head = head->next;
        }
        return temp->next;
    }
};