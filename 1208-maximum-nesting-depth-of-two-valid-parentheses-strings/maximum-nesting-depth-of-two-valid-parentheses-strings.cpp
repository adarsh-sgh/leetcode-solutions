class Solution {
public:

    // can we split s so that max depth is d 
    vector<int>v1;
    bool canSplit(string &s, int d){
        vector<int>ans(s.size());
        v1.clear();
        v1.resize(s.size());
        //open - closed
        int omc = 0;
        int omc2 = 0;
        for(int i = 0;i < s.size();i++){
            char c = s[i];
            if(omc == d && c == '('){
                // we can't accept anymore opening brackets
                omc2++;
                v1[i] = 1;
            }else if(c == '('){
                omc++;
                v1[i] = 0;
            }else if(omc){
                omc--;
                v1[i] = 0;
            }else{
                omc2--;
                v1[i] = 1;
                if(omc2 < 0) return false;
            }
            if(omc > d || omc2 > d || omc2 < 0 || omc < 0) return false;
        }
        if(omc || omc2) return false;
        return true;
    };
    vector<int> maxDepthAfterSplit(string seq) {
       for(int i = 1;i< seq.size();i++) {
        if(canSplit(seq,i)) {
            cout<<i;
            return v1;
        }
       }
       return {};
    }
};


// try splitting such that max depth is no longer than 1 if failed
// try splitting such that max depth is no longer than 2....
// looks like binary search problem after this