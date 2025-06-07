class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> sh(n+1);
        for(auto &rule:shifts) {
            int st = rule[0];
            int end = rule[1];
            int amount = rule[2]==1 ? 1: -1;
            sh[st]  +=amount;
            sh[end+1] -=amount;
        }
        for(int i=1;i<n;i++){
            sh[i] = sh[i]+sh[i-1];
        }

        for(int i=0;i<n;i++){
            int shift = sh[i]%26;
            if(shift<0) shift+=26;
            s[i] = ((s[i]-'a') + shift)%26+'a';
        }
        return s;

    }
};