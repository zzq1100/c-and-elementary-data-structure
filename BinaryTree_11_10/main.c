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

	return 0;
}