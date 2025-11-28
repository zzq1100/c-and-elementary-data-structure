#include"BinaryTree.h"

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
int main()
{
	BTNode* root = CreateBinaryTree();
	PrevOrder(root);
	printf("\n");
	printf("TreeSize: %d\n", TreeSize(root));
	printf("TreeLeafSize: %d\n", TreeLeafSize(root));
	BTNode* find = TreeFind(root, 5);
	if (find == NULL)
		printf("NO\n");
	else
		printf("Yes\n");
	return 0;
}