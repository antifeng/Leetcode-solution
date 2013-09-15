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
		//Remember: 
		//1. queue and stack in STL
    //2. vector.back == vector[size], vector.front == vector[0]
    //3. queue.pop == vector.pop_front(it is not exist in vector)
    //4. queue.push == vector.push_back()
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        vector<int> veclevel;
        queue<TreeNode*> levelone, leveltwo, tmp;
        levelone.push(root);
        while(true){
            while(!levelone.empty()) {
                TreeNode* cur = levelone.front();
                veclevel.push_back(cur->val);
                if (cur->left)
                    leveltwo.push(cur->left);
                if (cur->right)
                    leveltwo.push(cur->right);
                levelone.pop();
            }
            res.push_back(veclevel);
            veclevel.clear();
            if (leveltwo.empty())
                break;
            else{
                tmp = levelone;
                levelone = leveltwo;
                leveltwo = tmp;
            }
        } //end while
        return res;
    }
};
