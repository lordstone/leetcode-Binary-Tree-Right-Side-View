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
public:
    vector<int> rightSideView(TreeNode* root) { 
        vector<int> arr;
        if(root == NULL) return arr;
        arr.push_back(root->val);
        if(root->right == NULL && root->left == NULL) return arr;
        vector<int> arrL = rightSideView(root->left);
        vector<int> arrR = rightSideView(root->right);
        arr.insert(arr.end(),arrR.begin(), arrR.end());
        if(arrL.size() > arrR.size()){
            arr.insert(arr.end(),arrL.begin() + arrR.size(), arrL.end());
        }
        return arr;
    }
};
