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
    ListNode * putInFront(ListNode *l,int num){
        ListNode *lnew = new ListNode(num);
        lnew ->next = l;
        return lnew;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reversing
        ListNode *a = l1,*b = l2;
        int diff = 0;
        int n1 = 0, n2 = 0;
        while(a){
            a = a->next;
            n1++;
        }
        while(b){
            b = b->next;
            n2++;
        }
        if(n1>n2){
            swap(n1,n2);
            swap(l1,l2);
        }
        // n1 < n2
        diff = n2 - n1;
        ListNode *ans = nullptr;
        a = l1;b = l2;
        while(diff--){
            ans = putInFront(ans,b->val);
            b = b->next;
        }

        while(n1-- && n2--){
            // b->val += a->val;
            ans = putInFront(ans,a->val + b->val);
            assert(a && b);
            a = a->next;
            b = b->next;
        }
        ListNode *curr = ans;
        int carry = 0;
        while(curr){
            int val = curr->val + carry;
            curr->val = val %10;
            carry = val/10;
            curr = curr->next;
        }
        curr = ans;
        ListNode *prev = nullptr, *ppv = nullptr; 
        while(curr){
            ppv = prev;
            prev = curr;
            curr = curr->next;
            if(prev)prev->next = ppv;
        }
        if(carry)prev = putInFront(prev,carry);
        return prev;

       return ans;
    }
};