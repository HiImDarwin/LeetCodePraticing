class Solution {
public:
    //  Using string find way
        int strStr(string haystack, string needle) {
        size_t res = haystack.find(needle);
        if(res == string::npos) return -1;
        return res;
    }
    
};