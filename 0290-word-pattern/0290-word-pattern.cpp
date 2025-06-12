class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> cTs;
        unordered_map<string, char> sTc;
        stringstream ss(s);
        string word;
        int i=0;
        while(ss>>word) {
            char c = pattern[i];
            if(i>=pattern.size()) return false;

            if(cTs.count(c)) {
                if(cTs[c]!=word) return false;
            } else {
                if(sTc.count(word)) return false;
                cTs[c] = word;
                sTc[word] = c;
            }

            i++;
        }
        return i==pattern.size();
    }
};