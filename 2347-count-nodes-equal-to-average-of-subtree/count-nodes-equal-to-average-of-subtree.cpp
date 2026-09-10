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
    struct Counter {
        int count, sum, hits;
        operator int() { return hits;}
    };
    Counter averageOfSubtree(TreeNode* root) {
        if(root == nullptr) return {0,0,0};
        Counter left = averageOfSubtree(root->left);
        Counter right = averageOfSubtree(root->right);
        int count = left.count + right.count + 1;
        int sum = left.sum + right.sum + root->val;
        int hits = left.hits + right.hits + (root->val == sum / count);
        return {count, sum, hits};
    }
};