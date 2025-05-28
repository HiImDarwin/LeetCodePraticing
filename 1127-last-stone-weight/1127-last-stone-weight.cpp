class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int N = stones.size();
        for(int i=N/2-1;i>=0;i--) {
            adjustDown(stones,i);
        }

        while(stones.size()>1) {
            int fir = stones[0];
            removeRoot(stones);
            int sec  =  stones[0];
            if(fir == sec) {
                removeRoot(stones);
            } else {
                stones[0] = fir-sec;
                adjustDown(stones,0);
            }
        }
        return stones.empty() ? 0 : stones[0];

        
    }

    void adjustDown( vector<int> &hp, int root){
        int N = hp.size();
        while(true) {
            int biggest = root;
            int l = root*2+1;
            int r = root*2+2;
            if(l<N && hp[l]>hp[biggest]) biggest = l;
            if(r<N && hp[r]>hp[biggest]) biggest = r;
            if(biggest == root) break;
            swap(hp[root], hp[biggest]);
            root = biggest;
        }
    }

    void removeRoot( vector<int> &hp) {
        hp[0] = hp.back();
        hp.pop_back();
        adjustDown(hp,0);
    }
};