class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(),vector<bool> (board[0].size(),false));
        bool res = false;
        for(int i=0; i<board.size(); ++i) {
            for( int j =0; j<board[0].size(); ++j){
                if(board[i][j] == word[0]) res=trace(board,word,i,j,0,used);
                if(res) return true;
            }
        } 
        return false;
    }
    bool trace(vector<vector<char>>& board, string &word,int i,int j,int index, vector<vector<bool>> &used){

        if(index==word.length()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(used[i][j] || board[i][j]!=word[index]) return false;
        used[i][j] = true;
        bool res =  trace(board,word,i+1,j,index+1,used) ||
                    trace(board,word,i-1,j,index+1,used) ||
                    trace(board,word,i,j+1,index+1,used) ||
                    trace(board,word,i,j-1,index+1,used);
        used[i][j] =false;
        return res;
    }
};