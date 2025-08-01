/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // My dummy way
    // Node* copyRandomList(Node* head) {
    //     if(!head) return head;
    //     unordered_map<Node*,int> nodePool; // for new node
    //     vector<Node*> linkPool; // for old node link
    //     int i=0;

    //     //first round
    //     Node* curr = head;
    //     nodePool.insert({curr,i++});
    //     Node* newHead = new Node(curr->val);
    //     linkPool.push_back(newHead);
        
        
    //     Node* tmp = newHead;
    //     curr =curr->next;
    //     while(curr) {
    //         nodePool.insert({curr,i++});
    //         tmp->next = new Node(curr->val);
    //         tmp = tmp->next;
    //         linkPool.push_back(tmp);
    //         curr = curr->next;
    //     }

    //     curr = head;
    //     tmp = newHead;
    //     while(curr) {
    //         if(!curr->random) {
    //             tmp -> random = nullptr;
    //         } else {
    //             int index = nodePool[curr->random];
    //             tmp->random = linkPool[index];
    //         }
    //         curr = curr-> next;
    //         tmp = tmp->next;
    //     }
    //     return newHead;
    // }

    // better code style with hash
    // Node* copyRandomList(Node* head) {
    //     if (!head) return nullptr;

    //     unordered_map<Node*,Node*> nodeMap;
    //     Node *curr = head;
    //     while(curr) {
    //         nodeMap[curr] = new Node(curr->val);
    //         curr = curr->next;
    //     }

    //     Node* newHead = nodeMap[head];
    //     curr = head;
    //     while(curr) {
    //         newHead -> next = nodeMap[curr->next];
    //         newHead -> random = curr->random ? nodeMap[curr->random] : nullptr;
    //         newHead = newHead->next;
    //         curr = curr->next;
    //     }
    //     return nodeMap[head];
    // }


    //Interleave node copy trick
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* curr = head;
        while(curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr= head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* newHead = head->next;
        Node* tmp = newHead;
        curr = head;
        while(curr) {
            curr->next = tmp->next;
            curr = curr->next;
            if(curr) {
                tmp->next = curr->next;
                tmp = tmp-> next;
            }

        }
        return newHead;
    }
};