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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode *slow,*fast,*pslow = nullptr;
        slow = fast = head;
        while(fast && fast ->next != nullptr){
            fast = fast->next->next;
            // if(fast) fast = fast->next;
            pslow = slow;
            slow = slow->next;
        }
        pslow->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);

        root->left = sortedListToBST(head);

        root->right = sortedListToBST(slow->next);
        return root;
    }
};