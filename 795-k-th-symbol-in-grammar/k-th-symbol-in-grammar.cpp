class Solution {
public:
    bool firstTime = true;
    int kthGrammar(int n, int k) {
        if(firstTime){k--;firstTime = false;}
        if(n==1) return 0;
        return (kthGrammar(n-1,k/2) + k & 1) % 2;
    }
};
