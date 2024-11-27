class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        sort(q.begin(),q.end());
        // end, start
        multiset<array<int,2>>st;
        multiset<array<int,2>>ast;
        int n = nums.size();
        int j = 0;
        int req = 0;
        for(int i = 0;i<n;i++){
            // fill all q with st <= i
            while(j < q.size() && q[j][0] <= i){ast.insert({q[j][1], q[j][0]});j++;}
            // remove q that ended before i 
            while(st.size() && (*st.begin())[0] < i){
                st.erase(st.begin());
            }
            while(st.size() < nums[i]){
                // put ast.back into st ans++
                if(ast.empty() || (*ast.rbegin())[0] < i) return -1;
                st.insert(*ast.rbegin());
                req++;
                ast.erase(--ast.end());
            }
        }
        return q.size() - req;
    }
};