// 105. Construct Binary Tree from Preorder and Inorder Traversal

//basic method, using recursion - same method as the one being told to solve.
// no helper functions created.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0)
        {
            return NULL;
        }
        else if (inorder.size()==1)
        {
            TreeNode* root=new TreeNode(inorder[0]);
            return root;
        }
        else
        {
            int rootindex=-1;
            for(int i=0;i<inorder.size();i++)
            {
                if(inorder[i]==preorder[0])
                {
                    rootindex=i;
                    break;
                }
            }
            // v2 = vector<int>(v1.begin() + 1, v1.end());
            vector<int> in1=vector<int>(inorder.begin(), inorder.begin()+rootindex);
            vector<int> pre1=vector<int>(preorder.begin()+1, preorder.begin()+rootindex+1);
            // assert(in1.si)
            vector<int> in2=vector<int>(inorder.begin()+rootindex+1, inorder.end());
            vector<int> pre2=vector<int>(preorder.begin()+rootindex+1, preorder.end());
            
            TreeNode* root=new TreeNode(preorder[0]);
            TreeNode* left1=buildTree(pre1,in1);
            TreeNode* right1=buildTree(pre2,in2);
            root->left=left1;
            root->right=right1;
            return root;
        }
        return NULL;
    }
};