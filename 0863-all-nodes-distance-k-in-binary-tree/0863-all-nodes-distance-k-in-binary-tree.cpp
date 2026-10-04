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
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        int distance= 0;
        while(!q.empty()){
            int size= q.size();
            if(distance==k){
                vector<int>ans;
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left !=NULL && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                 if(node->right !=NULL && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(parent.count(node)&& !visited.count(parent[node])){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            distance ++;
        }
        return {};
    }
};