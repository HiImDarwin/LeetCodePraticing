class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> used(n,false);
        int res=0;
        backtracking(used,tiles,res);
        return res;
    }
    void backtracking(vector<bool> &used, string &tiles,int &res) {
        unordered_set<char> rep;
        for(int i=0; i<used.size(); ++i) {
            if(rep.count(tiles[i])) continue;
            if(used[i]) continue;
            used[i]=true;
            rep.insert(tiles[i]);
            res++;
            backtracking(used,tiles,res);
            used[i] = false;
        }
    }
};