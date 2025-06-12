class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45) return {};
        vector<int> sol;
        vector<vector<int>> res;
        int sum=0;
        backtracking(sol,res,1,k,n,sum);
        return res;
    }

    void backtracking(vector<int> &sol,vector<vector<int>> &res,int start, int k,int target ,int &sum) {
        if(sum == target && sol.size() ==k) {
            res.push_back(sol);
        }
        if(sol.size() >k || start > 9 || sum >target) return;

        for(int i=start;i<=9;++i) {
            sol.push_back(i);
            sum+=i;
            backtracking(sol,res,i+1,k,target,sum);
            sol.pop_back();
            sum-=i;
        }
    }
};