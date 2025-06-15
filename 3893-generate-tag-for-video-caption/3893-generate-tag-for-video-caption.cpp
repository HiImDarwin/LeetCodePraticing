class Solution {
public:
    string generateTag(string caption) {
        string res="#";
        int i=0;
        while(i<caption.length() && res.length()<100) {
            char c = caption[i];
            if(c == ' '){
                while((c == ' ' || !isalpha(c)) && i+1<caption.length()) {
                    c = caption[++i];
                }
                if(isalpha(c)) {
                    res+=toupper(c);  
                }
            } else if (isalpha(c)) {
                res+=tolower(c);
            } 
            i++;
        }
        res[1] = tolower(res[1]);
        return res;
    }
};