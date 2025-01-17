class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
       vector<int>orig(n);
       int xa = 0;
       for(auto &x:derived)xa ^= x;
       if(xa != 0) return false;
       return true;
    //    orig[0] = 0;
    //    for(int i = 1;i< n;i++){
    //     orig[i] = org[i-1] ^ derived[i-1];
    //    }

    }
};