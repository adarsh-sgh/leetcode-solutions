class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>st;
        for(int i = 0;i<ast.size();i++){
            if(!ast[i])continue;
            while(st.size() && st.back() > 0 && st.back() + ast[i] < 0)st.pop_back();
            if(st.size() && ast[i] < 0 ){
                int bk = st.back();
                if(ast[i] + bk == 0)st.pop_back();
                if(ast[i] + bk>=0)continue;
            }
            st.push_back(ast[i]);
        }
        return st;
    }
};