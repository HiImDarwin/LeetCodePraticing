class Solution {
public:
    string generateTag(string caption) {
        string res="#";
        for(int i=0; i<caption.length() && res.length()<100; ++i) {
            char c = caption[i];
            if(c == ' '){
                continue;
            } else if (isalpha(c)) {
                if(i!= 0 && caption[i-1] == ' ') res+=toupper(c);
                else                    res+=tolower(c);
            } 
        }
        res[1] = tolower(res[1]);
        return res;
    }
};