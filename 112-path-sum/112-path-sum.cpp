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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        int sum = 0;
        bool ans = 0;
        if(root == NULL)
        {
            return false;
        }
        targetSum -= root->val;
        if ( targetSum == 0 && root->left == NULL && root->right == NULL )
        {
            return 1;
        }


      if(root->left)
        ans = ans | hasPathSum(root->left, targetSum);
      if(root->right)
        ans = ans | hasPathSum(root->right, targetSum);

      return ans;
    }
    
};