class Solution {
public:
    // write with priority queue
    // don't need to worry about the tree balance
    // vector<string> findRelativeRanks(vector<int>& score) {
    //     int N = score.size();
    //     priority_queue<pair<int,int>> heap;
    //     for (int i=0; i<N; i++) {
    //         heap.push({score[i],i});
    //     }

    //     vector<string> rank(N);
    //     int place = 1;
    //     while(!heap.empty()) {
    //         int index = heap.top().second;
    //         heap.pop();
    //         if (place ==1) {
    //             rank[index] ="Gold Medal";
    //         } else if (place ==2) {
    //             rank[index] ="Silver Medal";
    //         } else if (place ==3) {
    //             rank[index] ="Bronze Medal";
    //         } else {
    //             rank[index] = to_string(place);
    //         }
    //         place++;
    //     }
    //     return rank;
    // }

    //heap solution
    vector<string> findRelativeRanks(vector<int>& score) {
        int N=score.size();
        vector<pair<int,int>> heap;
        for(int i=0; i< N; i++) {
            heap.push_back({score[i],i});
        }
        for(int i=N/2-1; i>=0; i--) {
            adjustDown(heap, i ,N);
        }
        vector<string> res(N);
        for(int place =1 ;place<=N; place++){
            pair<int,int> top = heap[0];
            int index = top.second;

            if(place ==1) res[index] = "Gold Medal";
            else if(place ==2) res[index] = "Silver Medal";
            else if(place ==3) res[index] = "Bronze Medal";
            else {
                res[index] = to_string(place);
            }
            heap[0] = heap.back();
            heap.pop_back();
            adjustDown(heap, 0, heap.size());
        }
        return res;
    }

private:
    void adjustDown(vector<pair<int,int>>& heap, int root, int n) {
        while (true) {
            int largest =root;
            int l = 2*root+1;
            int r = 2*root+2;
            
            if(l<n && heap[l].first>heap[largest].first) largest = l;
            if(r<n && heap[r].first>heap[largest].first) largest = r;

            if (largest == root) break;

            swap(heap[root],heap[largest]);

            root = largest; // this is the key point
        }
    }

};