#define _CRT_SECURE_NO_WARNINGS 1

//226.翻转二叉树
typedef struct TreeNode TNode;
struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
        return NULL;
    TNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

//100.相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL || q == NULL)
    {
        if (p == NULL && q == NULL)
            return true;
        else
            return false;
    }
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//101.对称二叉树
typedef struct TreeNode TNode;
bool check(TNode* p, TNode* q)
{
    if (p == NULL || q == NULL)
    {
        if (p == NULL && q == NULL)
            return true;
        else
            return false;
    }
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    return check(root->left, root->right);
}

//572.另一棵树的子树
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL || q == NULL)
    {
        if (p == NULL && q == NULL)
            return true;
        else
            return false;
    }
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL || subRoot == NULL)
    {
        if (root == NULL && subRoot != NULL)
            return false;
        if (root != NULL && subRoot == NULL)
            return true;
    }
    if (root->val != subRoot->val)
    {
        if (isSubtree(root->left, subRoot))
            return true;
        else if (isSubtree(root->right, subRoot))
            return true;
        else
            return false;
    }
    if (isSameTree(root, subRoot))
        return true;
    else
    {
        if (isSubtree(root->left, subRoot))
            return true;
        else if (isSubtree(root->right, subRoot))
            return true;
        else
            return false;
    }
}