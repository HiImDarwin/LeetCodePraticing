class Solution {
public:
    string longestNiceSubstring(string s) {
        unordered_set<char> missing;
        for (char c : s) {
            if (islower(c)) missing.insert(toupper(c));
            else missing.insert(tolower(c));
        }
        for (int i = 0; i < s.size(); i++) {
            if (missing.count(s[i])) {
                continue;
            }
            string s1 = longestNiceSubstring(s.substr(0, i));
            string s2 = longestNiceSubstring(s.substr(i + 1));
            return s1.size() >= s2.size() ? s1 : s2;
        }
        return s;
    }
};



/*
  What is the stop satuation for right pointer 
  
  1. window size set as char num  so the num will be 1 ~ 26
  2. 
 the question want us return earliest occurrence longest substring
 It must be sliding window

*/