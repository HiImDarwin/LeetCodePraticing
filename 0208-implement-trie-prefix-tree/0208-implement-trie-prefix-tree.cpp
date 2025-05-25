class Trie {
public:
    Trie() {
        //create root node
        root = new TrieNode;
    }
    
    void insert(string word) {
        // find longest common
        TrieNode *tmp = root;
        for(char &c: word){ 
            if(tmp->child.find(c)!=tmp->child.end()){ //find node exist
                tmp = tmp->child[c];
            } else { //build new node 
                TrieNode *newNode = new TrieNode;
                tmp->child[c] = newNode;
                tmp = newNode;
            }
        }
        if(!tmp->isWord) {
            tmp->isWord = true;
        }
    }
    
    bool search(string word) {
        TrieNode *tmp = root;
        for(char &c: word){ 
            if(tmp->child.find(c)!=tmp->child.end()){ //find node exist
                tmp = tmp->child[c];
            } else { 
                return false;
            }
        }
        return (tmp->isWord) ? true: false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for(char &c: prefix){ 
            if(tmp->child.find(c)!=tmp->child.end()){ //find node exist
                tmp = tmp->child[c];
            } else { 
                return false;
            }
        }
        return true;
    }
private:
    struct TrieNode {
        bool isWord=false;
        unordered_map<char,TrieNode*> child;
    };
    TrieNode *root;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */