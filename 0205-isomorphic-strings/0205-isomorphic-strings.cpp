class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!= t.length()) return false;
        unordered_map<char,char> sTt;
        unordered_map<char,char> tTs;
        for(int i=0;i<s.length();++i){
            if(sTt.count(s[i])){
                if( sTt[s[i]] != t[i] ) return false;
            } else {
                if(tTs.count(t[i])) return false;
                sTt[s[i]] = t[i];
                tTs[t[i]] = s[i];
            }
        }
        return true;
    }
};