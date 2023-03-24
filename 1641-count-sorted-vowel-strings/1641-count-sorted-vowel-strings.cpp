class Solution {
public:
    int countVowelStrings(int n) {
        long long x = 1;
        for(int i =1;i<=4;i++){
            x *= (n + i);
        }
        return x / 24;

    }
};