class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int N = score.size();
        priority_queue<pair<int,int>> heap;
        for (int i=0; i<N; i++) {
            heap.push({score[i],i});
        }

        vector<string> rank(N);
        int place = 1;
        while(!heap.empty()) {
            int index = heap.top().second;
            heap.pop();
            if (place ==1) {
                rank[index] ="Gold Medal";
            } else if (place ==2) {
                rank[index] ="Silver Medal";
            } else if (place ==3) {
                rank[index] ="Bronze Medal";
            } else {
                rank[index] = to_string(place);
            }
            place++;
        }
        return rank;
    }

};