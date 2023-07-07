class Solution {
public:
    int maxConsecutiveAnswers(string ak, int k) {
        int ans = 0;
        // int t = 0;
        
        string tf = "TF";
        for(int z = 0;z<2;z++)
        {
            int t = 0, i = 0;
            for(int j = 0;j<ak.size();j++){
            t += (ak[j]==tf[z]);
            while( t>k){
                t -= (ak[i]==tf[z]);
                i++;
            }
            ans = max(ans,j-i+1);
        }
        }
        return ans;
    }
};