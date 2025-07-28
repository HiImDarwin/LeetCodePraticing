class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      int n = ingredients.size();
      unordered_map<string, int> indexMap;
      vector<vector<int>> next(n);
      vector<int> inDegree(n);
      unordered_set<string> sup;

      for (int i = 0; i < n; ++i) {
        indexMap[recipes[i]] = i;
      }

      for (auto stuck :supplies) {
        sup.insert(stuck);
      }

      queue<int> qu;
      for (int i = 0; i < n; ++i) {
        for (auto ingredient : ingredients[i]) {
          if(indexMap.find(ingredient) != indexMap.end()) {
            inDegree[i]++;
            next[indexMap[ingredient]].push_back(i);
          }
        }
        if(inDegree[i] == 0) {
          qu.push(i);
        }
      }

      vector<string> res;
      while (!qu.empty()) {
        int recipeIndex = qu.front();
        qu.pop();
        bool canMake = true;
        for(auto need : ingredients[recipeIndex]) {
          if(sup.find(need) == sup.end()) {
            canMake = false;
            break;
          }
        }
        if (canMake) {
          res.push_back(recipes[recipeIndex]);
          sup.insert(recipes[recipeIndex]);
          for (auto nextRec : next[recipeIndex]) {
            inDegree[nextRec]--;
            if (inDegree[nextRec] == 0) {
              qu.push(nextRec);
            }
          }
        }
      }
      return res;
    }
};

/*

if the prev can cook the next can be cook



*/