/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(root==nullptr) return {};
        queue<Node *> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            int n = q.size();
            ans.push_back(q.front()->data);
            while(n--){
                Node *temp = q.front();
                q.pop();
                
                if(temp->left){
                    q.push(temp-> left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};
