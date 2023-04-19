class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>pu;
        int popi = 0;
        for(auto &&x:pushed){
            pu.push(x);
            while(!pu.empty() && pu.top() == popped[popi]){
                popi++;
                pu.pop();
            }
        }
        return popi == popped.size();
    }
};