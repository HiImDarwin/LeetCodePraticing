class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
      vector<vector<long long>> minCost(26,vector<long long>(26, LLONG_MAX));
      //O(E)
      for(int i = 0; i < original.size(); i++) {
        int u = original[i]-'a';
        int v = changed[i]-'a';
        long long w = cost[i];
        minCost[u][v] = min(minCost[u][v], w);        
      }
      //O(V^3) view as constant V = 26
      for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
          for (int j = 0; j < 26; j++) {
            if (minCost[i][k] == LLONG_MAX ||  minCost[k][j]  == LLONG_MAX ) {
              continue;
            }
            minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
          }
        }
      }
      long long res = 0;
      //O(S)
      for (int i = 0; i < source.length(); ++i) {
        if(source[i] == target[i]) {
          continue;
        }
        if(minCost[source[i]-'a'][target[i]-'a'] == LLONG_MAX) return -1;
        res += minCost[source[i]-'a'][target[i]-'a'];
      }
      return res;
    }
};


/*

take char as node 
original[i] ---- cost ----> changed[i] as edge directed edge
O(E+S)
*/