class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i = 0, j = tokens.size() - 1;
        int scr = 0;
        while(i<j){
            if(power < tokens[i]){
                if(scr <= 0)break;
                power += tokens[j--];
                scr--;
            }
            power -= tokens[i++];
            scr ++;
        }
        if(i==j && power >= tokens[i])scr++;
        return scr;
    }
};