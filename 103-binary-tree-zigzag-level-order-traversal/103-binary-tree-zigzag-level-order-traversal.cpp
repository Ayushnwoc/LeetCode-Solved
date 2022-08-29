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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        zigzag(root , 0 ,ans);
        for(int i = 0 ;i<ans.size();i++){
            if(i%2 == 1){
                reverse(ans[i].begin() , ans[i].end());
            }
        }
        return ans;
    }
    void zigzag(TreeNode* root , int index , vector<vector<int>>&ans){
        if(root == NULL){
            return;
        }
        if(ans.size()<=index){
            vector<int>a;
            ans.push_back(a);
        }
        ans[index].push_back(root->val);
        zigzag(root->left , index + 1 , ans);
        zigzag(root->right , index + 1 , ans);
    }
};