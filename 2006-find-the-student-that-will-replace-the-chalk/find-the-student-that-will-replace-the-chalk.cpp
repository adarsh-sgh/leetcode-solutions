class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       long long sum = accumulate(chalk.begin(), chalk.end(),0ll);
        k %= sum;
        cout<<k;
        for(int i = 0;i<chalk.size();i++){
            k -= chalk[i];
            if(k < 0) return i;    
        }
        return -1;
    }
};