class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int startIdx = 0;
        while (startIdx < s.length()) {
            string tmp;
            if ((startIdx + k) > s.length() ) {
                    tmp = s.substr(startIdx);
                    while (tmp.size() < k) {
                        tmp += fill;
                    }
                }
            else {
                tmp = s.substr(startIdx, k);
            }
            res.push_back(tmp);
            startIdx += k;
        }
        return res;
    }
};