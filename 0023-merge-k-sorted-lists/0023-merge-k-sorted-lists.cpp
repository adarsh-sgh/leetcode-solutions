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
    void mergeLists(ListNode*& l1, ListNode*& l2) {
  if (!l1) return;
  if (!l2) {
    swap(l1, l2);
    return;
  }
  if (l1->val < l2->val) swap(l1, l2);
  mergeLists(l1, l2->next);
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
  if(lists.empty()) return nullptr;
  for (int i = 0;i < lists.size() - 1;i++) {
    mergeLists(lists[i], lists[i + 1]);
  }
  return lists.back();
}
};