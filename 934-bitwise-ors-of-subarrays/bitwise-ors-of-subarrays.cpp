class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
     set<int>ans, curr, curr2;
     for(auto &x:arr){
        curr2 = {x};
        ans.insert(x);
        for(auto &y:curr){
            ans.insert( x | y );
            curr2.insert( x | y );
        }
        swap(curr, curr2);
     }   
     return ans.size();
    }
};