class Solution {
public:
    int getNum(int i, int j, int k){
        return i + j * 10 + k * 100;
    }
    int totalNumbers(vector<int>& digits) {
       // n * n * n
       int n = digits.size();
        set<int> se;
       for(int i = 0;i < n;i++){
        for(int j = 0; j < n;j++){
            for(int k = 0; k < n; k++){
                if(i == j || j ==k || i == k || digits[k] == 0) continue;
                // i, j, k -> put it 
                int x = getNum(digits[i],digits[j],digits[k]);
                if(x % 2 == 0) se.insert(x);
            }
        }
       }
       return se.size();
    }
};