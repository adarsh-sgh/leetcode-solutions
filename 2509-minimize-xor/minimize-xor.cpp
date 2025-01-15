class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n2 = __builtin_popcount(num2);
        int x = 0;
        for(int i = 31;i>=0;i--){
            if(n2 == 0) break;
            if(num1 >> i & 1){
                x |= (1<<i);
                n2--;
            }
        }
        for(int i = 0;i<=31;i++){
            if(n2==0) break;
            if( x >> i & 1) continue;
             x |= (1<<i);
             n2--;
        }    
        return x;
    }
};