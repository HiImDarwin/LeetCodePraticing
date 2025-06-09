class Solution {
public:
    // struct Compare {
    //     bool operator() (pair<char,int> a,pair<char,int> b) {
    //         if (a.second < b.second) return true;
    //         else if (a.second == b.second && a.first > b.first) return true;
    //         return false;
    //     }
    // };
    // string frequencySort(string s) {
    //     unordered_map<char,int> bucket;
    //     for(char &c : s) {
    //         bucket[c]++;
    //     }
    //     //prioirty can't handl unordered_map
    //     vector<pair<char, int>> items(bucket.begin(), bucket.end());
    //     priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> qu(items.begin(), items.end());
        
    //     string res="";
    //     while(!qu.empty()) {
    //         auto [ch, freq] = qu.top();
    //         qu.pop();
    //         res += string(freq, ch);
    //     }
    //     return res;
    // }

    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto ch: s) mp[ch]++;
        vector<pair<char,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second >b.second;
        });
        string ans = "";
        for(auto &[ch, freq]: vec) {
            ans += string(freq,ch);
        }
        return ans;
    }
};