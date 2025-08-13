class Solution {
  vector<int> group;
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
      group.assign(n+1,0);
      iota(group.begin(),group.end(),0);
      sort(connections.begin(), connections.end(),[](vector<int>& a, vector<int>& b){
        return (a[2] < b[2]);
      });

      int islandCount = n, index = 0;
      int totalCost = 0;
      while (islandCount > 1 && index < connections.size()) {
        int nodeU = connections[index][0];
        int nodeV = connections[index][1];
        int weight = connections[index][2];
        if (UniteGroup(nodeU, nodeV)) {
          islandCount--;
          totalCost += weight;
        }
        index++;
      }
      return islandCount == 1 ? totalCost : -1;
    }


    int FindRoot(int node) {
      if (group[node] != node) {
        group[node] = FindRoot(group[node]);
      }
      return group[node];
    }

    bool UniteGroup(int nodeX, int nodeY) {
      int groupX = FindRoot(nodeX);
      int groupY = FindRoot(nodeY);

      if (groupX == groupY) {
        return false;
      }
      if (groupX < groupY) {
        group[groupY] = groupX;
      } else {
        group[groupX] = groupY;
      }
      return true;
    }

};