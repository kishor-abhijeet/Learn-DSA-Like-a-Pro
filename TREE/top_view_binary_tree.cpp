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
    vector<int> topView(Node *root) {
        // code here
        unordered_map<int, int> mp;
		int hd = 0;
		queue<pair<Node*, int>> q;
		q.push({root, 0});
		int mx = 0;
		int mn = 0;
		while (!q.empty()) {
			pair<Node*, int> curr = q.front();
			q.pop();
			Node* node = curr.first;
			hd = curr.second;
			if(mp.find(hd) == mp.end()){
			    mp[hd] = node->data;
			}
			
			if (node->left) {
				q.push({node->left, hd - 1});
			}
			if (node->right ){
			   q.push({node->right, hd+1});
			
			}
			mx = max(mx, hd);
			mn = min(mn, hd);
		}
		vector<int> res;
		for(int i=mn; i<=mx; i++) {
		    res.push_back(mp[i]);
		}
		return res;
    }
};
