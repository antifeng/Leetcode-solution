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
private:
	//Key idea: the last element of postorder seq is the root node which can be used to divide inorder seq
    typedef vector<int>::iterator iter;
    TreeNode *buildTreeHelper(iter instart, iter inend, iter poststart, iter postend) {
		TreeNode* ptree = NULL;
		if ( inend == instart || postend == poststart)	
    		return ptree;
		int inLen = inend - instart;
		int postLen = postend - poststart;
		if (inLen == 1 && postLen == 1)  {
			ptree = new TreeNode(instart[0]);
		}
		else{
			//set the root
			ptree = new TreeNode(*(postend-1));
			for (iter miditor = instart; miditor < inend; miditor++) {
				if (*miditor == *(postend-1)) { //Calc the position of iterator is not easy
						ptree->left = buildTreeHelper(instart, miditor, poststart, poststart+(miditor-instart));
                		ptree->right = buildTreeHelper(miditor+1, inend, postend-(inend-miditor), postend-1);
				}
			}//end for
		}//end else
        return ptree;
	}
	
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		TreeNode* ptree = NULL;		
		ptree = buildTreeHelper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
		return ptree;
	}
};
