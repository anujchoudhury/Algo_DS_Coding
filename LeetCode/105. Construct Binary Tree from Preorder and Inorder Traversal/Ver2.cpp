// 105. Construct Binary Tree from Preorder and Inorder Traversal

// Trying to decrease the memory consumption, reusing the original vector array
// Same method, using the universal map to remember the place of each element in preorder vector in the inorder vector
// Recursive solution.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& h1,int l1,int r1,int l2, int r2) {
        if(r1<l1)
        {
            // cout<<" "<<l1<<r1<<endl;
            // cout<<"null "<<l2<<r2<<endl;
            return NULL;
        }
        else if(r1==l1)
        {
            // cout<<preorder[l1]<<" "<<l1<<r1<<endl;
            // cout<<preorder[l1]<<"ha "<<l2<<r2<<endl;
            TreeNode* root=new TreeNode(preorder[l1]);
            return root;
        }
        TreeNode* root=new TreeNode(preorder[l1]);
        int rootindex=h1[preorder[l1]];
        // cout<<preorder[l1]<<" "<<l1<<r1<<endl;
        // cout<<rootindex<<" "<<l2<<r2<<endl<<endl;
        // there are rootindex elements before the root element in the inorder queue, beginning from l2
        root->left=buildTree(preorder,inorder,h1,l1+1,l1-l2+rootindex,l2,rootindex-1);
        root->right=buildTree(preorder,inorder,h1,rootindex+1+r1-r2,r1,rootindex+1,r2);
        return root;
    }
    
        
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
            unordered_map<int,int> h1;
            int rootindex=-1;
            for(int i=0;i<inorder.size();i++)
            {
                h1[inorder[i]]=i;
            }
            return buildTree(preorder,inorder,h1,0,inorder.size()-1,0,preorder.size()-1);
        }
        return NULL;
    }
};