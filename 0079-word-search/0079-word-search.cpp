class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for(int i=0; i<board.size(); ++i) {
            for( int j =0; j<board[0].size(); ++j){
                if(board[i][j] == word[0]) res=trace(board,word,i,j,0);
                if(res) return true;
            }
        } 
        return false;
    }
    bool trace(vector<vector<char>>& board, string &word,int i,int j,int index){

        if(index==word.length()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(board[i][j]!=word[index]) return false;
        char c=board[i][j];
        board[i][j] = '#';
        bool res =  trace(board,word,i+1,j,index+1) ||
                    trace(board,word,i-1,j,index+1) ||
                    trace(board,word,i,j+1,index+1) ||
                    trace(board,word,i,j-1,index+1);
        board[i][j] =c;
        return res;
    }
};