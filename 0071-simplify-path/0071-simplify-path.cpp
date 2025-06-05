class Solution {
public:
    // string simplifyPath(string path) {
    //     vector<string> st;
    //     int index = 0;
    //     while(index < path.length()){
    //         while(index < path.length() && path[index] == '/') {
    //             index++;
    //         }
    //         if(index == path.length()) break;

    //         int startPos=index;

    //         while(index < path.length() && path[index] != '/') {
    //             index++;
    //         }
    //         string part = path.substr(startPos,index-startPos);

    //         if(part ==".") {
    //             continue;
    //         } else if (part == "..") {
    //             if(!st.empty())st.pop_back();
    //         } else {
    //             st.push_back(part);
    //         }
    //     }
    //     string res;

    //     for(string x: st) {
    //         res += "/";
    //         res = res  + x;
    //     }
    //     return res.empty() ? "/" : res; 
        
    // }

    string simplifyPath(string path) {
        
        stringstream ss(path);
        string comp;
        while(getline(ss, comp, '/')) {
            if(comp == "" || comp == ".") continue;
            if(comp == ".."){
                if(!st.empty()) st.pop_back();
            } else {
                st.push_back(comp);
            }
        }
        stringstream  res;
        for( string &s :st) {
            res << "/" << s;
        }
        return res.str().empty() ? "/" : res.str();
    }
    vector<string> st;
};