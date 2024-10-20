class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char> vops;
        vector<char>tfb;
        set<char> ops = {'|','&','!'};
        for(auto &c:expression){
            if(c==',')continue;
            if(c != ')'){
                if(ops.count(c)){
                   vops.push_back(c); 
                }else{
                    tfb.push_back(c);
                }
            }else{
                char tb = tfb.back();tfb.pop_back();
                bool x = tb == 't';
                while(tfb.back() != '('){
                    auto curr = tfb.back();
                    tfb.pop_back();
                    auto ob = vops.back();
                    if(ob == '&'){
                       x = x & (curr == 't');
                    }else{
                        x = x | (curr == 't');
                    }
                }
                tfb.pop_back();// remove (
                if(vops.back() == '!'){
                    x = !x;
                }
                vops.pop_back();
                tfb.push_back(x ? 't' : 'f');
            }
        }
        return tfb[0] == 't';
    }
};