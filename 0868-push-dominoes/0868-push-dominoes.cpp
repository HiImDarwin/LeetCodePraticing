class Solution {
public:
    string pushDominoes(string dominoes) {
      queue<pair<int,int>> qu; 

      for (int i = 0; i < dominoes.size(); ++i) {
        if(dominoes[i] == 'R') {
          qu.push({i,1});
        } else if (dominoes[i] == 'L') {
          qu.push({i,-1});
        }
      }

      while(!qu.empty()) {
        int fallingNum =  qu.size();
        unordered_set<int> eachRoundOp;
        

        for (int i = 0; i < fallingNum; ++i) {
          auto [index, dir] = qu.front();
          qu.pop();
          if (index + dir  >= 0 && index + dir < dominoes.size() && dominoes[index + dir] == '.') {
            eachRoundOp.insert(index + dir);
            dominoes[index + dir] = dominoes[index];
          } else if (index + dir  >= 0 && index + dir < dominoes.size() && dominoes[index + dir] != dominoes[index]) {
            if(eachRoundOp.find(index + dir) != eachRoundOp.end()) {
              eachRoundOp.erase(index + dir);
              dominoes[index + dir] = '.';
            }
          }
        }

        for(auto& x : eachRoundOp) {
          if(dominoes[x] == 'R') {
            qu.push({x,1});
          } else {
            qu.push({x,-1});
          }
        }
        eachRoundOp.clear();
      }

      return dominoes;
    }
};

/*

next = .
  next next =  dif > do nothing
  next next = same  > do
  next next = .     >

*/