class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      int num_child = g.size();
      int num_cookie = s.size();
      sort(g.begin(),g.end());
      sort(s.begin(),s.end());
      int res=0;
      int i=0,j=0;
      while(i<num_child && j<num_cookie) {
        if(g[i]<=s[j]){
            res++;
            i++;
            j++;
        } else {
            j++;
        }
      }
      return res;
    }
};