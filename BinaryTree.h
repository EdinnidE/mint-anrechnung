#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef struct bTreeNode_s {
	struct bTreeNode_s* left;
	struct bTreeNode_s* right;
	int value;
}bTreeNode;

void FillBinaryTree(bTreeNode** headNode, const int* const values, const unsigned int length);
void FillSingleValue(bTreeNode** node, const int value);
void TraverseAndPrintTree(bTreeNode** node);
void AddNode(bTreeNode** headNode, int value);
bTreeNode* GetNodeWithValue(bTreeNode** node, int valueToFind);
void deleteTree(bTreeNode** node);

#endif