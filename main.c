#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

#define ARR_SIZE 19

int main(int argc, char const* argv[]) {

	// type any values (in integer range) in any orderr (keep size of Array <= ARR_SIZE)
	int values[ARR_SIZE] = {5, 3, 8, 2, 1, 6, 7, 4, 9, 0, -5, -2, -1, -9, -3, -7, -8, -6, -4};

	//cretae headnode
	bTreeNode* headNode = (bTreeNode*)calloc(1, sizeof(bTreeNode));

	FillBinaryTree(&headNode, values, ARR_SIZE);
	printf("---------- printing tree ----------\n\n");
	TraverseAndPrintTree(&headNode);
	AddNode(&headNode, 100);
	AddNode(&headNode, -100);
	AddNode(&headNode, 50);
	printf("\n---------- printing tree ----------\n\n");
	TraverseAndPrintTree(&headNode);
	printf("\n");

	bTreeNode* tempNode = GetNodeWithValue(&headNode, 4);

	printf("address of gotten? node addr is: %d and the value is: %d", (int)tempNode, tempNode->value);
	printf("\n");

	tempNode = GetNodeWithValue(&headNode, 50);

	printf("address of gotten? node addr is: %d and the value is: %d\n", (int)tempNode, tempNode->value);
	printf("\n");

	deleteTree(&headNode);
	printf("\n");
	printf("---------- printing tree ----------\n");
	TraverseAndPrintTree(&headNode);
	printf("\n");

	return 0;
}