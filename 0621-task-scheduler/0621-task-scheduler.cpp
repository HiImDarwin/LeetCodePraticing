class Solution {
public:
    // use heap decrease value;
    // minus top n node each round until  heap got empty
    // if node number is not enough stall++;
    int leastInterval(vector<char>& tasks, int n) {   
        unordered_map<char,int> mp;
        int stall_count = 0;
        for (char &c : tasks) {
            mp[c]++;
        }
        priority_queue<int> maxHp;
        for (auto &node: mp) {
            maxHp.push(node.second);
        }

        while(!maxHp.empty()){
            vector<int> tmp;
            for(int i=0;i<n+1;i++) {
                if(!maxHp.empty()) {
                    if(maxHp.top()>1) tmp.push_back(maxHp.top()-1);
                    maxHp.pop();
                } else if (!tmp.empty()) {
                    stall_count++;
                }
            }
            for(int &x: tmp) {
                maxHp.push(x);

            }
        }
        return tasks.size()+stall_count;
    }
};