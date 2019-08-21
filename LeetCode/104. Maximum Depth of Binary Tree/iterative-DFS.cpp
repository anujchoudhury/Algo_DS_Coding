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
    int maxDepth(TreeNode* root) {
        if(!root){return 0;}
        else
        {
            stack<TreeNode*> nodes;
            stack<int> values;
            int maxlevel=0,temp;
            nodes.push(root);
            values.push(1);
            TreeNode *curr;
            //this extra stack is used simply for storing the level of nodes
            while(!nodes.empty())
            {
                curr = nodes.top();
                nodes.pop();
                temp = values.top();
                values.pop();

                maxlevel=max(maxlevel,temp);
                if(curr->left)
                {
                    nodes.push(curr->left);
                    values.push(temp+1);
                }
                if(curr->right)
                {
                    nodes.push(curr->right);
                    values.push(temp+1);
                }
            }
            return maxlevel;
        }
    }
};