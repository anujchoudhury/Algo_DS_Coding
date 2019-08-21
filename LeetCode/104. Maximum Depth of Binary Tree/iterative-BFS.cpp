class Solution {
public:
int solution2(TreeNode *root){
    if(root == NULL) return 0;
    queue<TreeNode *> que;
    que.push(root);
    int depth = 0, count;
    TreeNode *left, *right;
    while(que.empty() == false){
        depth++;
        count = que.size();
        for(int i = 0; i < count; i++){
            left = que.front()->left;
            if(left) que.push(left);
            right = que.front()->right;
            if(right) que.push(right);
            que.pop();
        }
    }
    return depth;
}
};