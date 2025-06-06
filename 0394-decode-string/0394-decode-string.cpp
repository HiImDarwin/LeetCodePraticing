class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
    string decode(string &s, int &i) {
        string res;
        int num = 0;
        while(i<s.size()) {
            char c =s[i];

            if(isdigit(c)) {
                num = num*10+(c-'0');
                i++;
            } else if(c=='[') {
                i++; //skip [
                string inner = decode(s,i);
                while(num-- > 0) res += inner;
                num=0;
            } else if(c==']') {
                i++;
                return res;
            } else {
                res+=c;
                i++;
            }
        }
        return res;
    }
};