/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int Height(TreeNode* tree){
        
        if (!tree)
            return 0;
        int lHeight, rHeight;
        if (tree->left)
            lHeight = Height(tree->left);
        else 
            lHeight = 0;
        if (tree->right)
            rHeight = Height(tree->right);
        else 
            rHeight = 0;
            
        if( lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1)
            return -1;
        else
            return max(lHeight, rHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
           return true;
        if (!(root->left) && !(root->right))
            return true;
            
        int lHeight = Height( root->left);
        int rHeight = Height( root->right);
        if ( abs( lHeight - rHeight) > 1
                || lHeight == -1 || rHeight==-1)
            return false;
        else
            return true;
    }
};
