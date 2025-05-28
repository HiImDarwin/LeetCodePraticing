class Solution {
public:
    // ***************heap***********************
    // use heap decrease value;
    // minus top n node each round until  heap got empty
    // if node number is not enough stall++;
    // int leastInterval(vector<char>& tasks, int n) {   
    //     unordered_map<char,int> mp;
    //     int stall_count = 0;
    //     for (char &c : tasks) {
    //         mp[c]++;
    //     }
    //     priority_queue<int> maxHp;
    //     for (auto &node: mp) {
    //         maxHp.push(node.second);
    //     }

    //     while(!maxHp.empty()){
    //         vector<int> tmp;
    //         for(int i=0;i<n+1;i++) {
    //             if(!maxHp.empty()) {
    //                 if(maxHp.top()>1) tmp.push_back(maxHp.top()-1);
    //                 maxHp.pop();
    //             } else if (!tmp.empty()) {
    //                 stall_count++;
    //             }
    //         }
    //         for(int &x: tmp) {
    //             maxHp.push(x);

    //         }
    //     }
    //     return tasks.size()+stall_count;
    // }
    //**************methmatic method******************
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> map(26,0);
        for( auto &c: tasks) {
            map[c-'A']++;
        }
        sort(map.begin(),map.end());
        int maxFreq = map[25];
        int maxFreqCount = 0;
        for (int i=25; i>=0 && map[i] == maxFreq; i--) {
            maxFreqCount++;
        }
        int minTime = (maxFreq-1)*(n+1)+maxFreqCount;
        return max(minTime,(int)tasks.size());

    }
};