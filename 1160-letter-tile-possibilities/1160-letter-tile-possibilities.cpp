class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        vector<bool> used(n,false);
        int res=0;
        backtracking(used,tiles,res);
        return res;
    }
    void backtracking(vector<bool> &used, string &tiles,int &res) {

        for(int i=0; i<used.size(); ++i) {
            if(i>0 && tiles[i] == tiles[i-1] &&  !used[i - 1]) continue;
            if(used[i]) continue;
            used[i]=true;
            res++;
            backtracking(used,tiles,res);
            used[i] = false;
        }
    }
};