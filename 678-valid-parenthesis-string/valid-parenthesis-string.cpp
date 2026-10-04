class Solution {
public:
    bool checkValidString(string s) {
        // ensure omc >= 0 always
        // and omc < star in the end
        // greedily thinking ( should be as early as possible and ) as late as
        // possible use as much stars as possible (unless parity disallows)
        int omc = 0, star = 0;
        for (auto& x : s) {
            if (x == '(')
                omc++;
            else if (x == ')')
                omc--;
            else
                star++;
        }
        if (abs(omc) > star)
            return false;
        int on = 0, cn = 0;
        if (omc > 0) {
            cn = omc;
        } else {
            on = -omc;
        }
        star -= abs(omc);
        cn += star / 2;
        on += star / 2;
        cout<<cn<<' '<<on<<'\n';
        for (auto& c : s) {
            if (c != '*')
                continue;
            if (on-- > 0) {
                c = '(';
            }
        }
        cout<<s;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*' && cn-- > 0) {
                s[i] = ')';
            }
        }
        omc = 0;
        for(auto &c:s){
            if(c == '(')omc++;
            else if(c == ')')omc--;
            if(omc < 0) return false;
        }
        return omc == 0;
    }
};