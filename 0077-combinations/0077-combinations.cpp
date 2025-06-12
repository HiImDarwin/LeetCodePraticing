class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> sol;
        vector<vector<int>> res;
        backtracking(sol,res,1,n,k);
        return res;
        
    }

    void backtracking(vector<int> &sol,vector<vector<int>> &res,int start, int n,int k) {
        if(sol.size() ==k){
            res.push_back(sol);
            return;
        }
        for(int i=start;i<=n;i++){
            sol.push_back(i);
            backtracking(sol,res,i+1,n,k);
            sol.pop_back();
        }
    }
};