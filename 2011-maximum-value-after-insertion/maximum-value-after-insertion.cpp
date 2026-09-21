class Solution {
public:
    string maxValue(string n, int x) {
        // you either have to maximise it or minimise it based on the sign
        // maximise => start from left
        // first element that's less than x, put x before it

        // minimise => start from left
        // first element > x, put it before it
        bool no_change = true;

        string ans = "";
        // ans.push_back(char( 5 + '0'));
        // return ans;
        if (n[0] == '-') {
            ans.push_back('-');
            for (int i = 1; i < n.size(); i++) {
                if (n[i] - '0' > x && no_change) {
                    // n.insert(i,to_string(x));
                    ans.push_back(char(x + '0'));
                    no_change = false;
                }
                ans.push_back(n[i]);
            }
        } else {
            for (int i = 0; i < n.size(); i++) {
                if (n[i] - '0' < x && no_change) {
                    ans.push_back(char(x + '0'));
                    // n.insert(i,to_string(x));
                    no_change = false;
                }
                ans.push_back(n[i]);
            }
        }
        if (no_change)
            ans.push_back(char(x + '0'));
        return ans;
    }
};