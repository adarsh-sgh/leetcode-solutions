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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // minDistance distance bw adjacent cp
        // maxDistance distance bw first and last cp
        // first and previous cp
        int fcp = -1, pcp = -1;
        int pv = head->val;
        head = head->next;
        int i = 0;
        int minDistance = 1e6;
        int maxDistance = -1;
        while (head && head->next) {
            if (1ll * (head->val - pv) * (head->val - head->next->val) > 0) {
                // this is cp
                if (pcp != -1) {
                    minDistance = min(minDistance, i - pcp );
                    maxDistance = max(maxDistance, i - fcp);
                }
                pcp = i;
                if (fcp == -1)
                    fcp = i;
            }
            pv = head->val;
            head = head->next;
            i++;
        }
        // cout<<minDistance;
        if (maxDistance == -1)
            minDistance = -1;
        return vector<int>{minDistance, maxDistance};
    }
};