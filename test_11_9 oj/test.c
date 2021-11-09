#define _CRT_SECURE_NO_WARNINGS 1

//965.单值二叉树
bool isUnivalTree(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    if (root->left && root->left->val != root->val)
        return false;
    if (root->right && root->right->val != root->val)
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

//144.二叉树的前序遍历
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _prevorder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;
    a[*pi] = root->val;
    (*pi)++;
    _prevorder(root->left, a, pi);
    _prevorder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* a = (int*)malloc(size * sizeof(int));
    int i = 0;
    _prevorder(root, a, &i);
    *returnSize = size;
    return a;
}