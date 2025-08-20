class TaskManager {
    struct Task{
      Task(int user, int task,int pri) {
        userId = user;
        taskId = task;
        priority = pri;
      }
      int userId;
      int taskId;
      int priority;
    };
    // struct Cmp {
    //   bool operator() (const pair<int,int> &a,const pair<int,int> &b){
    //     if (a.first == b.first) {
    //       return a.second < b.second;
    //     }
    //     return a.first < b.first;
    //   };
    // };

    unordered_map<int, Task*> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
      for (auto& vec : tasks) {
        int u = vec[0];
        int t = vec[1];
        int p = vec[2];
        this->add(u,t,p);
      }
    }

    ~TaskManager() {
      for (auto& [id, t] : mp) {
        delete t;
      }
    }
    
    void add(int userId, int taskId, int priority) {
      Task* newTask = new Task(userId, taskId, priority);
      pq.push({priority,taskId});
      mp[taskId] = newTask;
    }
    
    void edit(int taskId, int newPriority) {
      Task* modidfyTask = mp[taskId];
      if (newPriority != modidfyTask->priority) {
        modidfyTask->priority = newPriority;
        pq.push({newPriority,taskId});
      }
    }
    
    void rmv(int taskId) {
      Task* rmTask = mp[taskId];
      delete rmTask;
      mp.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
          auto[priority, taskId] = pq.top();
          pq.pop();
          if (mp.count(taskId) && mp[taskId]->priority == priority) {
            Task* t = mp[taskId];
            int userId = t->userId;
            delete t;
            mp.erase(taskId);
            return userId;
          }
        }
        return -1;
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


/*
 Sort with priority
 the value can be modify
 red black tree 
 Edit O(log n)
 Add O(log n)
 Remove O(log n)

*/