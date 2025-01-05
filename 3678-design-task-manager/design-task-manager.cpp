class TaskManager {
public:
    map<int, map<int,int>>ptu;
    // for rmv and edit
    map<int,int>tp;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &t:tasks){
            // t -> utp
            ptu[t[2]][t[1]] = t[0];
            tp[t[1]] = t[2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        ptu[priority][taskId] = userId;
        tp[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
       auto p = tp[taskId];
       auto u = ptu[p][taskId];
       ptu[p].erase(taskId);
       if(ptu[p].empty())ptu.erase(p);
       tp[taskId] = newPriority;
       ptu[newPriority][taskId] = u;
    }
    
    void rmv(int taskId) {
        auto p  = tp[taskId];
        ptu[p].erase(taskId);
        if(ptu[p].empty())ptu.erase(p);
        tp.erase(taskId);
    }
    
    // highest priority, taskId  return userId
    int execTop() {
        if(ptu.empty()) return -1;
       auto tp = ptu.rbegin()->second.rbegin();
       // tp.first, tp.second
       int u = tp->second;
       rmv(tp->first);
       return u;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */