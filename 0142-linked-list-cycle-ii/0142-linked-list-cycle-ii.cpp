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
        ListNode * slow,*fast;
        slow = fast = head;
        if(!slow) return slow;
        slow = slow->next;
        if(slow == nullptr) return nullptr;
        fast = fast->next->next;
        
        while(slow != fast){
             if(fast == nullptr || fast->next == nullptr){
                return nullptr;
            }
            slow = slow->next;
           
            fast = fast->next->next;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};