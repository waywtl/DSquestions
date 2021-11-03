#define _CRT_SECURE_NO_WARNINGS 1

//��ָOffer 07.�ؽ�������
typedef struct TreeNode TreeNode;
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (preorder == NULL || inorder == NULL || preorderSize == 0)
        return NULL;

    int rootVal = preorder[0];
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    //�ýڵ�ΪҶ�ڵ�ʱ
    if (preorderSize == 1)
        return root;

    //�ҵ�����������еĸ�
    int* inorderRoot = inorder;
    while (*inorderRoot != rootVal)
        inorderRoot++;

    //���������������
    int leftLength = inorderRoot - inorder;
    int rightLength = inorderSize - leftLength - 1;

    //����������
    if (leftLength > 0)
        root->left = buildTree(preorder + 1, leftLength, inorder, leftLength);
    //����������
    if (rightLength > 0)
        root->right = buildTree(preorder + leftLength + 1, rightLength, inorderRoot + 1, rightLength);

    return root;
}

//��ָOffer 08.����������һ���ڵ�
typedef struct TreeLinkNode TreeLinkNode;
struct TreeLinkNode* GetNext(struct TreeLinkNode* pNode)
{
    if (pNode == NULL)
        return NULL;
    TreeLinkNode* pNext = NULL;
    //�ýڵ���������ʱ����һ���ڵ㼴Ϊ��������������Ҷ
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
        //��������ʱ�����ýڵ��ýڵ�ĸ��ڵ�Ϊ�丸�ڵ����ڵ㣬����һ���ڵ�Ϊ���ǵĸ��ڵ�
        while (parent != NULL && cur == parent->right)
        {
            cur = parent;
            parent = parent->next;
        }
        pNext = parent;
    }
    return pNext;
}