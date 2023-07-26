class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        for(auto x:piles)q.push(x);
        while(k--){
            auto x = q.top();
            q.pop();
            x = x - x/2;
            q.push(x);
        } 
        int ans = 0;
        while(q.size()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};