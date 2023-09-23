class LRUCache {
public:
struct DLL {
  int key;
  int val;
  DLL* next;
  DLL* prev;
  DLL(int k, int v, DLL* p, DLL* n) {
    key = k;
    val = v;
    next = n;
    prev = p;
  }
};
  int cap;
  DLL* phead = new DLL(-1, -1, nullptr, nullptr);
  DLL* ntail = new DLL(-1, -1, phead, nullptr);
  unordered_map<int, DLL*>mp;
  LRUCache(int capacity) {
    phead->next = ntail;
    cap = capacity;
  }

  int get(int key) {
    if (!mp.count(key))return -1;
    auto node = mp[key];
    del(node);
    node->prev = phead;
    node->next = phead->next;
    phead->next->prev = node;
    phead->next = node;
    return node->val;
  }

  void del(DLL* node) {
    // mp.erase(node->key);
    DLL* nxt = node->next;
    DLL* prv = node->prev;
    nxt->prev = prv;
    prv->next = nxt;
  }
  void put(int key, int value) {
    if(mp.count(key)){
        del(mp[key]);
        mp.erase(key);
    }
    if (mp.size() == cap ) {
      mp.erase(ntail->prev->key);
      del(ntail->prev);
    }
    DLL* phn = phead->next;
    phead->next = new DLL(key, value, phead, phn);
    phn->prev = phead->next;
    mp[key] = phead->next;
  }
};