class Solution {
public:
    //  Using string find way
    //int strStr(string haystack, string needle) {
    //     int strStr(string haystack, string needle) {
    //     size_t res = haystack.find(needle);
    //     if(res == string::npos) return -1;
    //     return res;
    // }

    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m =haystack.size();
        if(n>m) return -1;
        
        for(int start =0; start <= m-n; start++) {
            int peek=0;
            while(peek<n && haystack[start+peek] == needle[peek]) {
                peek++;
            }
            if(peek == n) return start;
        }
        return -1;
    }

};