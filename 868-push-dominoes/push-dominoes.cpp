class Solution {
public:
    string pushDominoes(string dominoes) {
        // for each index store
        // nearest L on right 
        // nearest R on left       
        int n = dominoes.size();
        vector<int>LonR(n);
        vector<int>RonL(n);
        int x = -1e7;
        for(int i = 0;i< n;i++){
            if(dominoes[i] == 'R')x = i;
            else if(dominoes[i] == 'L') x = -1e7;
            RonL[i] = i - x;
        }
        x = 1e7;
        for(int i = n-1;i>=0;i--){
            if(dominoes[i] == 'L')x = i;
            else if(dominoes[i] == 'R')x = 1e7;
            LonR[i] = x - i;
        }
        for(int i = 0; i < n;i++){
            if(dominoes[i] == '.'){
               if(LonR[i] < RonL[i] && LonR[i] < 1e6)dominoes[i] = 'L';
               else if(LonR[i] > RonL[i] && RonL[i] < 1e6) dominoes[i] = 'R';
            }
        }
        return dominoes;

    }
};