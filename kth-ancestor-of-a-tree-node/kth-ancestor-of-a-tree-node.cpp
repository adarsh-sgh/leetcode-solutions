class TreeAncestor {
public:
  vector<vector<int>>up;
  TreeAncestor(int n, vector<int>& parent) {
    up.resize(n, vector<int>(20, -1));
    //2 ^0
    for (int i = 0;i < parent.size();i++) {
      up[i][0] = parent[i];
    }
    //2 ^ i
    for (int i = 1;i < 20;i++) {
      for (int node = 0;node < n;node++) {
        int np = up[node][i - 1];
        if (np != -1)up[node][i] = up[np][i - 1];
      }
    }
  }

  int getKthAncestor(int node, int k) {
    for (int i = 0;i < 20;i++) {
      if (node == -1)return -1;
      if (k & (1 << i))node = up[node][i];
    }
    return node;
  }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */