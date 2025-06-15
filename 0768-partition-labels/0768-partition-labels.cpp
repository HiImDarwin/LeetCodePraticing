class Solution {
public:
    vector<int> partitionLabels(string s) {
      unordered_map<char,pair<int,int>> mp;
      for(int i = 0; i < s.length(); ++i){
        if(mp.count(s[i])) {
            mp[s[i]].second = i;
        } else {
            mp[s[i]].first = i;
            mp[s[i]].second = i;
        }
      }
      vector<pair<int,int>> intervals;
      for(auto &interval: mp){
        intervals.push_back(interval.second);
      }
      sort(intervals.begin(),intervals.end(),[](pair<int,int> &a, pair<int,int> &b){
        return a.first < b.first;
      });
      vector<int> ans;
      int left= intervals[0].first;
      int right = intervals[0].second;
      for(auto &interval: intervals){
        if(right >= interval.first) {
            right = max(right,interval.second);
        } else {
            ans.push_back(right-left+1);
            left = interval.first;
            right =interval.second;
        }
      }
      ans.push_back(right-left+1);
      return ans;
    }
};