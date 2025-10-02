class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        long long ans = 0;
        long long eb = 0;
        while(nb){
            ans += nb;
            eb += nb;
            nb = 0;
            while(eb >= ne){
                nb++;
                eb-=ne;
                ne++;
            }
            cout<<nb<<' '<<ans;
        }
        return ans;
    }
};

// nb = 13 