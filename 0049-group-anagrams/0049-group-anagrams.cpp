class Solution {
public:
    // my way
    // time cost 20:31
    // result TLE in testcase
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<unordered_map<char,int>> stringMap;
    //     vector<vector<string>> res;
    //     for(string &word : strs) {
    //         int setIndex=0;
    //         bool found = false;
    //         for(setIndex=0;setIndex<stringMap.size();setIndex++) {
    //             unordered_map<char,int> tmp = stringMap[setIndex];
    //             int i;
    //             for(i=0;i<word.size();i++) {
    //                 if(tmp[word[i]]-- < 0) break;
    //                 if(tmp[word[i]] == 0) tmp.erase(word[i]);
    //             }
    //             if(tmp.empty() && i == word.length()) {
    //                 found = true;
    //                 break;
    //             }
    //         }

    //         if(!found) {
    //             unordered_map<char,int> newSet;
    //             for(int i=0;i<word.length();i++){
    //                 newSet[word[i]]++;
    //             }
    //             stringMap.push_back(newSet);
    //             vector<string> newWord(1,word);
    //             res.push_back(newWord);
    //         } else {
    //             res[setIndex].push_back(word);
    //         }
    //     }

    //     return res;
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
        vector<vector<string>> res;
        unordered_map<string,int> Set;

        //sort every strs into a1b3c8 style
        for(int i = 0; i< strs.size(); i++){
            string tmpStr = strs[i];
            sort(tmpStr.begin(),tmpStr.end());
            if(Set.count(tmpStr)) {
                auto x = Set.find(tmpStr);
                res[x->second].push_back(strs[i]);
            } else {
                Set.insert({tmpStr,Set.size()});
                res.push_back(vector<string>{strs[i]});
            }
        }
        
        return res;
    }
};