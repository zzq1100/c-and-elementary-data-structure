#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int BTDataType;
typedef struct BinaryTree
{
	BTDataType val;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTNode;

BTNode* BTNodeApply(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	node->val = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTNode* CreateBinaryTree()
{
	BTNode* node1 = BTNodeApply(1);
	BTNode* node2 = BTNodeApply(2);
	BTNode* node3 = BTNodeApply(3);
	BTNode* node4 = BTNodeApply(4);
	BTNode* node5 = BTNodeApply(5);
	BTNode* node6 = BTNodeApply(6);
	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	return node1;
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	if (root->left == NULL && root->right == NULL)
		return 1;
	
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight : rightHeight;
}