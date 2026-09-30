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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)return{};
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
while(!q.empty()){
    auto curr= q.front();
    q.pop();
    TreeNode* node= curr.first;
    int col= curr.second.first;
    int row= curr.second.second;
    nodes[col][row].insert(node->val);
    if(node->left!=NULL){
        q.push({node->left,{col-1,row+1}});
    }
    if(node->right!=NULL){
        q.push({node->right,{col+1,row+1}});
    }
}
vector<vector<int>> ans;
for(auto& colEntry: nodes){
    vector<int>colValues;
    for(auto& rowEntry:colEntry.second){
        for(int value: rowEntry.second){
            colValues.push_back(value);
        }
    }
    ans.push_back(colValues);
}
return ans;

    }
};