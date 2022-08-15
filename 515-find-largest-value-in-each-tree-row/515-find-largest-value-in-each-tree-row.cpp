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
    vector<int> largestValues(TreeNode* root) {
        dfs(root , 0);
        vector<int>ans;
        for(int i = 0;i<a.size();i++)
        {
            int maxi= INT_MIN;
            for(int j = 0;j<a[i].size() ; j++)
            {
                maxi = max(a[i][j] , maxi);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
    void dfs(TreeNode* root , int val)
    {
        if(root == NULL)
        {
            return;
        }
        if(a.size() == val)
        {
            vector<int>w;
            a.push_back(w);
        }
        a[val].push_back(root->val);
        dfs(root->left , val+1);
        dfs(root->right , val+1);
    }
    vector<vector<int>>a;
};