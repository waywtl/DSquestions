#define _CRT_SECURE_NO_WARNINGS 1

//144.二叉树的前序遍历
/*int TreeSize(struct TreeNode* root)
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
}*/

//94.二叉树的中序遍历
/*int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _inorder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;
    _inorder(root->left, a, pi);
    a[*pi] = root->val;
    (*pi)++;
    _inorder(root->right, a, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* a = (int*)malloc(size * sizeof(int));
    int i = 0;
    _inorder(root, a, &i);
    *returnSize = size;
    return a;
}*/

//145.二叉树的后序遍历
/*int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _postorder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;

    _postorder(root->left, a, pi);
    _postorder(root->right, a, pi);
    a[*pi] = root->val;
    (*pi)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* a = (int*)malloc(size * sizeof(int));
    int i = 0;
    _postorder(root, a, &i);
    *returnSize = size;
    return a;
}*/

//104.二叉树的最大深度
/*int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}*/

//110.平衡二叉树
/*int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return abs(leftDepth - rightDepth) <= 1
        && isBalanced(root->left)
        && isBalanced(root->right);
}*/

//牛客网 二叉树遍历 
//已知前序遍历，输出中序遍历
/*#include <stdio.h>

typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
}TNode;

TNode* TreeCreat(char* str, int* pi)
{
    if (str[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }

    TNode* root = (TNode*)malloc(sizeof(TNode));
    if (root == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    root->val = str[*pi];
    (*pi)++;

    root->left = TreeCreat(str, pi);
    root->right = TreeCreat(str, pi);

    return root;
}

void InOrder(TNode* root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main()
{
    char str[100];
    scanf("%s", str);

    int i = 0;
    TNode* root = TreeCreat(str, &i);
    InOrder(root);
    return 0;
}*/