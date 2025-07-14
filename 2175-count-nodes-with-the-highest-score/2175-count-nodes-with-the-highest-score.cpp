// class Solution {
//   unordered_map<long long,int> Map;
//   vector<vector<int>> children;
// public:
//   int countHighestScoreNodes(vector<int>& parents) {
//     int n = parents.size();
//     children.resize(n);
//     for(int i = 0; i < n; ++i) {
//       if(parents[i] == -1) continue;
//       children[parents[i]].push_back(i);
//     }
//     dfs(0, n);
//     int maxVal = 0, count=0;
//     for(auto [val,num] : Map) {
//       if (val >= maxVal) {
//         maxVal = val;
//         count= num;
//       }
//     }
//     return count;
//   }

//   int dfs(int node,int n) {
//     vector<int> subtreeNode;
//     int totalChild = 0;
//     for(auto child : children[node]) {
//       int count = dfs(child, n);
//       subtreeNode.push_back(count);
//       totalChild += count;
//     }
//     int parentNode = totalChild + 1 == n ? 1 : n - totalChild - 1;
//     long long res = parentNode;
//     for(int x : subtreeNode) {
//       res *= x;
//     }
//     Map[res]++;
//     return totalChild+1;
//   }
// };


/*
When doing dfs we can calculate the above node num
children node number


*/
using LL = long long;
class Solution {
    unordered_map<LL,LL>Map;
    vector<vector<int>>children;
public:
    int countHighestScoreNodes(vector<int>& parents) 
    {
        int n = parents.size();
        children.resize(n);
        for (int i=1; i<n; i++)
        {           
            children[parents[i]].push_back(i);
        }
                
        dfs(0);
        
        LL maxVal = -1;
        LL num = 0;
        for (auto x: Map)
        {
            if (x.first > maxVal)
            {
                maxVal = x.first;
                num = x.second;
            }
        }
        
        return num;
    }
    
    int dfs(int node)
    {
        int n = children.size();
        vector<int>sub;
        int sub_total = 0;
        for (auto child: children[node])
        {
            sub.push_back(dfs(child));
            sub_total += sub.back();
        }        
        int U = n - (sub_total+1);
        LL ret = 1;
        if (U!=0) ret *= U;
        for (auto x: sub)
            if (x!=0) ret *= x;
        Map[ret]++;
        
        return sub_total+1;
    }
};