class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sol;
        backtracking(s,0,res,sol);
        return res;
    }

    void backtracking(string s,int start,vector<vector<string>> &res, vector<string> &sol) {
        if(start==s.length()) res.push_back(sol);
        for(int i=start;i<s.length();++i){
            if(isPalindrome(s,start,i)) {
                sol.push_back(s.substr(start,i-start+1));
                backtracking(s,i+1,res,sol);
                sol.pop_back();
            }
        }
    }

    bool isPalindrome(string &s,int left, int right){
        while(left<=right){
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
};