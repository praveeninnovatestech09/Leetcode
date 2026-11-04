/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*>st;
    bool reverse;
    BSTIterator(TreeNode* root, bool isreverse) {
        reverse = isreverse;
        pushAll(root);
    }
    void pushAll(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            if (reverse) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (reverse) {
            pushAll(temp->left);
        } else {
            pushAll(temp->right);
        }

        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;
        BSTIterator left(root, false);
        BSTIterator right(root, true);
        int low = left.next();
        int high = right.next();
        while (low < high) {
            int sum = low + high;

            if (sum == k) {
                return true;
            } else if (sum < k) {
                if (left.st.empty()) {
                    break;
                }
                low = left.next();
            } else {
                if (right.st.empty()) {
                    break;
                }
                high = right.next();
            }
        }

        return false;
    }
};