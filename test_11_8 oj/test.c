#define _CRT_SECURE_NO_WARNINGS 1

//814.二叉树剪枝
struct TreeNode* pruneTree(struct TreeNode* root)
{
    if (root == NULL)
        return NULL;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == NULL && root->right == NULL && root->val == 0)
        return NULL;
    return root;
}

//617.合并二叉树
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root2 == NULL)
        return root1;
    if (root1 == NULL)
        return root2;
    root1->val = root1->val + root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}