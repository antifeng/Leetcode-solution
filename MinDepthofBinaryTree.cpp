 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root==NULL)
            return 0;
        else {
            int lh = minDepth(root->left);
            int rh = minDepth(root->right);
            
            if (lh==0)
                return rh+1;
            if (rh==0)
                return lh+1;
            return (lh < rh) ? lh+1 : rh+1;
        }
    }
};
