#define _CRT_SECURE_NO_WARNINGS 1

//剑指Offer 07.重建二叉树
typedef struct TreeNode TreeNode;
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (preorder == NULL || inorder == NULL || preorderSize == 0)
        return NULL;

    int rootVal = preorder[0];
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    //该节点为叶节点时
    if (preorderSize == 1)
        return root;

    //找到在中序遍历中的根
    int* inorderRoot = inorder;
    while (*inorderRoot != rootVal)
        inorderRoot++;

    //求出左右子树长度
    int leftLength = inorderRoot - inorder;
    int rightLength = inorderSize - leftLength - 1;

    //构建左子树
    if (leftLength > 0)
        root->left = buildTree(preorder + 1, leftLength, inorder, leftLength);
    //构建右子树
    if (rightLength > 0)
        root->right = buildTree(preorder + leftLength + 1, rightLength, inorderRoot + 1, rightLength);

    return root;
}

//剑指Offer 08.二叉树的下一个节点
typedef struct TreeLinkNode TreeLinkNode;
struct TreeLinkNode* GetNext(struct TreeLinkNode* pNode)
{
    if (pNode == NULL)
        return NULL;
    TreeLinkNode* pNext = NULL;
    //该节点有右子树时，下一个节点即为右子树的最左子叶
    if (pNode->right != NULL)
    {
        TreeLinkNode* pRight = pNode->right;
        while (pRight->left)
            pRight = pRight->left;
        pNext = pRight;
    }
    else if (pNode->next != NULL)
    {
        TreeLinkNode* cur = pNode;
        TreeLinkNode* parent = pNode->next;
        //无右子树时，若该节点或该节点的父节点为其父节点的左节点，则下一个节点为它们的父节点
        while (parent != NULL && cur == parent->right)
        {
            cur = parent;
            parent = parent->next;
        }
        pNext = parent;
    }
    return pNext;
}