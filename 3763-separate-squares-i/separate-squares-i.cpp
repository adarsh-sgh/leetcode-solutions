class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l = 0, r = 1e9;
        auto neecheBada = [&](double m){
            // y = m
            double neeche = 0;
            double upar = 0;
            for(auto &s:squares){
                double y = s[1], l = s[2];
                // cout<<"y "<<y<<'\n';
                if(y + l <= m){
                    // neeche
                    neeche += l * l;
                    // cout<<" chamar "<<'\n';
                }else if(y >= m){
                    upar += l * l;
                }else{
                    // cout<<"cut "<<'\n';
                   // cut kar raha hai 
                   upar += l * abs(y + l - m);
                   neeche += l * abs(m - y);
                }
            }
            return neeche >= upar;
        };
        // cout<<neecheBada(1.8)<<" neeche bada"<<'\n';
        // false false false true true true
        for(int i = 0; i < 1e3;i++){
            double m = (l + r)/2.0;
            if(neecheBada(m)){
                r = m;
            }else{
                l = m;
            }
            // cout<<"m "<<m<<'\n';
        }
        return l;
    }
};