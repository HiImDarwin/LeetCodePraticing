class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
      int n = properties.size();
      sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) {
          return a[1] < b[1];
        }
        return a[0] > b[0];
      });
      stack<int> st;
      int res = 0;
      for (auto pro : properties) {
        int attack = pro[0];
        int defense = pro[1];
        while (!st.empty() && defense >= st.top()) {
          st.pop();
        }
        if (!st.empty()) {
          res++;
        }
        st.push(defense);
      }
      return res;
    }
};


/*
sort attack
sort defence
  prefix Greater
for each attak
for each defence previous greater (n^2 log n)



sort + sliding window (wrong)
+++++++
  *


sort + mask (wrong) i is too big can't used mask
build attack mask
build defense mask

and both mask if > 0 than there are at least 1 greater in both




*/