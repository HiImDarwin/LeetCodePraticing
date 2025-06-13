class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking("",n,n,res);
        return res;
    }
    void backtracking(string path,int left, int right, vector<string> &res) {
        if(left ==0 && right == 0) {
            res.push_back(path);
        }
        if(left>0) {
            backtracking(path+'(',left-1,right,res);
        }
        if(left<right){
            backtracking(path+')',left,right-1,res);
        }
    }
};