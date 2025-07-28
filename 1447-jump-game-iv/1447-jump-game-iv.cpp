class Solution {
public:
    int minJumps(vector<int>& arr) {
      int n = arr.size();
      unordered_map<int,vector<int>> valueMap;
      
      // index for every value for fast search
      for (int i = 0; i < n; ++i) {
        valueMap[arr[i]].push_back(i);
      }
      
      queue<int> positionQueue;
      vector<bool> visited(n,false);
      int jump = 0;
      positionQueue.push(0);
     
      while (!positionQueue.empty()) {

        int num = positionQueue.size();
        for (int i = 0; i < num; i++) {
          int index = positionQueue.front();
          positionQueue.pop();
          if (index == n - 1) {
            return jump;
          }

          if (index + 1 < n && !visited[index + 1]) {
            positionQueue.push(index + 1);
          }

          if (index - 1 >= 0 && !visited[index - 1]) {
            positionQueue.push(index - 1);
          }

          for(int nextIndex : valueMap[arr[index]]) {
            if(visited[nextIndex]) {
              continue;
            }
            visited[nextIndex] = true;
            positionQueue.push(nextIndex);
          }

          valueMap.erase(arr[index]);
        }
        jump++;
      }
      return -1;
        
    }
};


/*
question 
can jump forward and backward
DP state transfer
pos[i] = min({pos[i+1],pos[i-1],min{set{pos[i]}} +1);


BFS adjency 

1. is the array zero index?

2. 


*/