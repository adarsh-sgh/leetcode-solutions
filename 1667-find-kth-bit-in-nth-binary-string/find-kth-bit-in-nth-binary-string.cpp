class Solution {
public:
    int ans(int n,int k, vector<int>&l){
        if(n == 1) return 0;
        if(l[n-1] == k){
           return 1; 
        }else if(k < l[n-1]) {
            return ans(n-1,k,l);
        }else{
            return !ans(n-1, l[n] - k - 1,l);        
        }
        
    }
    char findKthBit(int n, int k) {
        k--;
        vector<int>l(21);
        l[1] = 1;
        for(int i = 2;i<=20;i++){
            l[i] = 2 * l[i-1] + 1;
        }
        return '0' + ans(n,k,l);

    }
    
};