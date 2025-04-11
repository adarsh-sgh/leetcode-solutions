class Solution {
public:
    vector<int>getDigs(int x){
        vector<int>ans;
        while(x){
            ans.push_back(x%10);
            x/=10;
        }
        return ans;
    }
    int isSymmetric(int x){
        vector<int>digs = getDigs(x);
        if(digs.size() & 1) return false;
        int sum = accumulate(digs.begin(), digs.end(),0ll);
        int sumHalf = 0;
        for(int i = 0;i< digs.size()/2;i++){
            sumHalf += digs[i];
        }
        return sumHalf * 2 == sum;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
       for(int i = low;i<=high;i++){
        ans += isSymmetric(i);
       } 
       return ans;
    }
};