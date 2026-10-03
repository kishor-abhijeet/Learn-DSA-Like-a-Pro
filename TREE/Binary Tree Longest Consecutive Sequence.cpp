/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* node) {
    if(node==NULL) return 0;

    int cnt = 1;
    int l_cnt, r_cnt;

    if (node->left && node->left->val == node->val+1) {
        l_cnt = 1+solve(node->left);
        cnt = max(l_cnt, cnt);
    }

    if (node->right && node->right->val == node->val+1) {
        r_cnt = 1+solve(node->right);
        cnt = max(r_cnt, cnt);
    }

    return cnt;
}
    int longestConsecutive(TreeNode* root) {
        // Your code goes here
        if(root == NULL) return 0;
        int ans = solve(root);
        if(root->left){
            ans = max(ans, longestConsecutive(root->left));
        }
        if(root->right){
            ans = max(ans, longestConsecutive(root->right));

        }
        return ans;
       
    }
};
