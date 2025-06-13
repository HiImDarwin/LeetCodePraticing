class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        //vector<string> sol;
        //backtracking(s,0,res,sol,0);
        string path;
        backtracking(s,0,res,path,0);
        return res;
    }

    // void backtracking(string s, int start, vector<string> &res ,vector<string> &sol,int dotCount) {
    //     if(start == s.length() && dotCount == 4) {
    //         res.push_back(sol[0]+"."+sol[1]+"."+sol[2]+"."+sol[3]);
    //         return;
    //     }
    //     if(dotCount > 3 || start >= s.length()) return;
    //     string tmp;
    //     for(int i=start; i<s.length() && i<start+3 ;++i) {
    //         tmp += s[i];
    //         if((tmp.length()>1 && tmp[0] == '0') || stoi(tmp) >255 ) break;
    //         sol.push_back(tmp);
    //         backtracking(s,i+1,res,sol,dotCount+1);
    //         sol.pop_back();
    //     }
    // }
    void backtracking(string s, int start, vector<string> &res ,string &path,int dotCount) {
        if(start == s.length() && dotCount == 4) {
            res.push_back(path.substr(0,path.length()-1));
            return;
        }
        if(dotCount > 3 || start >= s.length()) return;
        string tmp;
        for(int i=start; i<s.length() && i<start+3 ;++i) {
            tmp += s[i];
            if((tmp.length()>1 && tmp[0] == '0') || stoi(tmp) >255 ) break;
            int len = path.length();
            path += tmp +'.';
            backtracking(s,i+1,res,path,dotCount+1);
            path.erase(len);
        }
    }
};