class Solution {
public:
    Solution() {
        root = new Node();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        //insert in book
        for(string &st : wordDict) {
            Insert(st);
        }
        // find the word
        return searchWholeString(s);
        
    }
private:
    void Insert(std::string word){
        Node* tmp = root;
        for(char& c: word) {
            if(tmp->child[c-'a']){
                tmp = tmp->child[c-'a'];
            } else {
                tmp->child[c-'a'] = new Node;
                tmp = tmp->child[c-'a'];
            }
        }
        tmp->isWord = true;
    }


    bool searchWholeString(string s) {
        int n = s.length();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;
            Node* node = root;
            for (int j = i; j < n; ++j) {
                char c = s[j];
                if (!node->child[c - 'a']) break;
                node = node->child[c - 'a'];
                if (node->isWord) dp[j + 1] = true;
            }
        }
        return dp[n];
    }


    // bool searchWholeString(string s) {
    //     stack<int> shorterIndex;
    //     int index=0;
    //     Node *tmp = root;
    //     while(index<s.length()) {
    //         if(!tmp->child[s[index]-'a'] && shorterIndex.empty()) {
    //             return false;
    //         } else if(!tmp->child[s[index]-'a'] && !shorterIndex.empty()) {
    //             index = shorterIndex.top();
    //             shorterIndex.pop();
    //             tmp = root;
    //         } else {
    //             tmp = tmp->child[s[index]-'a'];
    //             index++;
    //             if(tmp->isWord) {
    //                 shorterIndex.push(index);
    //             }
    //             if(index == s.length() && !tmp->isWord && !shorterIndex.empty()) {
    //                 index = shorterIndex.top();
    //                 shorterIndex.pop();
    //                 tmp = root;
    //             }
    //         }
    //     }
    //     return tmp->isWord ? true: false;
    // }
    struct Node {
        bool isWord=false;
        Node* child[26];

        Node() {
            for (int i=0;i<26;i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;
};