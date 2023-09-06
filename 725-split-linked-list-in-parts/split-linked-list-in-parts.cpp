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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode *curr = head;
        while(curr){
            curr = curr->next;
            cnt++;
        }
        int seg  = cnt/k;
        int rem = cnt%k;
        cout<<cnt<<seg<<' '<<rem;
        vector<ListNode*>ans(k);
        curr = head;
        // return ans;
        for(int ki = 0;ki < k;ki++){
            ans[ki] = curr;
            for(int i = 0;i<seg-1 + (rem > 0);i++){
             curr = curr->next;
            }
            rem--;
            if(!curr) break;
            ListNode *nxt = curr->next;
            curr->next = nullptr;
            curr = nxt;
        }
        return ans;
    }
};