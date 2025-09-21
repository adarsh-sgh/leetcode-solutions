class MovieRentingSystem {
public:
    map<int, set<array<int,2>>>mcs;
    map<int, map<int,int>>msc;
    set<array<int,3>>csm;
    void add(int m, int s, int c){
        mcs[m].insert({c,s});
        msc[m][s] = c;
        // csm.insert({c,s,m});
    }
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
       for(auto &e:entries){
        auto s = e[0], m = e[1], c = e[2];
        add(m, s, c);
       } 
    }
     // movie_i, set<costi,shopi>
    vector<int> search(int movie) {
        // cout<<"--\n";
        vector<int>ans;
        // for(auto &x:mcs[movie])cout<<x[0]<<' '<<x[1]<<endl;
        for(auto &cs:mcs[movie]){
            if(ans.size() == 5)break;
            ans.push_back(cs[1]);
        }
        return ans;
    }

    // map<movie, shop -> cost
    void rent(int s, int m) {
      auto c = msc[m][s];
      mcs[m].erase({c,s});
    //   msc[m].erase(s);
      csm.insert({c,s,m});
    }
    
    void drop(int s, int m) {
        //! c = 0 always
        auto c = msc[m][s];
        add(m,s,c);
        csm.erase({c,s,m});
    }
    
        // set<costi, shopi, movie
    vector<vector<int>> report() {
      vector<vector<int>>ans;
      for(auto &x:csm){
        if(ans.size() == 5)break;
        ans.push_back({ x[1], x[2]});
      }
      return ans; 
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */