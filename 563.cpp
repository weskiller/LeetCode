//https://leetcode.com/problems/binary-tree-tilt
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int Tilt{0};
    int ChildTreeSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sumleft = ChildTreeSum(root->left);
        int sumright = ChildTreeSum(root->right);
        Tilt += abs(sumleft-sumright);
        return sumleft + sumright + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        if (root == NULL)
            return 0;
        return abs(ChildTreeSum(root->left) - ChildTreeSum(root->right)) + Tilt;
    }
};