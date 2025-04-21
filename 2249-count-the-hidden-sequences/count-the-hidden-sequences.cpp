class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
       // let seq[0] = 0
       // make the sequence
       // me = min_element(seq), mx = max_element(seq)
       // if(me < lower) inc all elements by atleast diff = lower - me
       // if(mx > upper) dec all elements by atleast mx - upper
       // both true return 0

       // bad plan 
       // just find the length of the seq. (mx - me)
       // find the diff bw permitted length and this length is the answer
       int n = d.size();
       vector<long long>seq(n+1);
       long long me = 0, mx = 0;
       for(int i = 1;i<=n;i++){
        seq[i] = seq[i-1] + d[i - 1];
        me = min(me, seq[i]);
        mx = max(mx, seq[i]);
       }
       long long actualLength = mx - me + 1;
       long long permittedLength = upper - lower + 1;
       return max(0ll, permittedLength - actualLength + 1);

    }
};