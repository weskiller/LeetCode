//https://leetcode.com/problems/symmetric-tree
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
private:
    bool ChildNodeMatch(TreeNode * left,TreeNode * right){
        if (left != NULL && right != NULL)
            if (left->val == right->val)
                return ChildNodeMatch(left->left,right->right) && ChildNodeMatch(left->right,right->left);
            else
                return false;
        else if (left == NULL && right == NULL)
            return true;
        else
            return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        else
            return ChildNodeMatch(root->left,root->right);
    }
};
