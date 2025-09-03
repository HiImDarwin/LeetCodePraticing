class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
      string initState;
      string finalState = "123450";

      for (int i = 0; i < 6; i++) {
        initState.push_back(board[i/3][i%3] + '0');
      }

      vector<vector<int>> neighbor = {
        {1,3},  
        {0,2,4},
        {1,5},
        {0,4},
        {1,3,5},
        {2,4}
      };

      unordered_set<string> visited;

      queue<pair<string,int>> qu;
      qu.push({initState,0});

      while (!qu.empty()) {
        auto [state, step] = qu.front();
        qu.pop();

        if (visited.find(state) != visited.end()) {
            continue;
        }
        visited.insert(state);
        if (state == finalState) {
          return step;
        }

        for (int i = 0; i < 6; i++) {
          if (state[i] != '0') continue;
          for (auto nei : neighbor[i]) {
            string newState = state;
            swap(newState[i],newState[nei]);
            qu.push({newState, step + 1});
          }
        }
      }

      return -1;
    }
};

/*
1 2 3
4 5 6


least number of moves  -> seems dp

state transfer each block have 0~5 value and six block we got 

each state move 1 block -> which block?
try every block for six block we can move each block go the different state 
push state into the queue

state 6!
bfs max 3 times

so the time complexity is  6!*3 O(1)


*/