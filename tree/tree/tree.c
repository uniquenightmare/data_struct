#define  _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"
BTNode * BinaryTreeCreate(BTDataType *a, int *pi)
{
	if (a[*pi] != '#')
	{
		BTNode *root = (BTNode *)malloc(sizeof(BTNode));
		root->val = a[*pi];
		++(*pi);
		root->Ltree = BinaryTreeCreate(a, pi);
		++(*pi);
		root->Rtree = BinaryTreeCreate(a, pi);
		return root;
	}
	else
	{
		return NULL;
	}
}
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->val);
		BinaryTreePrevOrder(root->Ltree);
		BinaryTreePrevOrder(root->Rtree);
	}
	
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		
		BinaryTreeINOrder(root->Ltree);
		printf("%c ", root->val);
		BinaryTreeINOrder(root->Rtree);
	}
}
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{

		BinaryTreePostOrder(root->Ltree);
		BinaryTreePostOrder(root->Rtree);
		printf("%c ", root->val);
	}
}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->Ltree) + BinaryTreeSize(root->Rtree) + 1;
}
void BinaryTreeDestory(BTNode** root)
{
	BTNode* root1 = *root;
	if (root1)
	{
		BinaryTreeDestory(&root1->Ltree);
		BinaryTreeDestory(&root1->Rtree);
		free(root1);
		*root = NULL;
	}
}
int  BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->Ltree ==NULL&& root->Rtree == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->Ltree) + BinaryTreeLeafSize(root->Rtree);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->Ltree, k - 1) + BinaryTreeLevelKSize(root->Rtree, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}
	ret = BinaryTreeFind(root->Ltree, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->Rtree, x);
	if (ret)
	{
		return ret;
	}
	return NULL;

}
void BinaryTreeLevelOrder(BTNode* root)
{
	//利用队列来实现
	//出头入头的左右孩子


}