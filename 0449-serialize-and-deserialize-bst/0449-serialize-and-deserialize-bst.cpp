/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // levelorder
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        queue<TreeNode*> qu;
        string res="[";
        qu.push(root);
        while(!qu.empty() ) {
            TreeNode* node = qu.front();
            qu.pop();
            if(node){
                res += to_string(node->val) +',';
                qu.push(node->left);
                qu.push(node->right);
            } else {
                res += "null,";
            }
        }
        res[res.length()-1] =']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if (data == "[]") return nullptr;

    vector<string> vals;
    string curr;
    for (int i = 1; i < data.size() - 1; ++i) {
        if (data[i] == ',') {
            vals.push_back(curr);
            curr = "";
        } else {
            curr += data[i];
        }
    }
    vals.push_back(curr); // 加上最後一個節點

    TreeNode* root = new TreeNode(stoi(vals[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (vals[i] != "null") {
            node->left = new TreeNode(stoi(vals[i]));
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != "null") {
            node->right = new TreeNode(stoi(vals[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;