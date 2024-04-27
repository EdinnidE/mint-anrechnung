#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

void FillBinaryTree(bTreeNode** headNode, const int* const values, const unsigned int length) {
  //directly fill in first value of tree. This value is the "base" for sorting the values
  (*headNode)->value = values[0];

  for (size_t i = 1; i < length; i++) { // here just go trough all given values
    FillSingleValue(headNode, values[i]);
  }
}

void FillSingleValue(bTreeNode** node, const int value) {
  if (!(*node)) {
    *node = (bTreeNode*)calloc(1, sizeof(bTreeNode));// if current node is empty -> create one with the given value
    (*node)->value = value;
    return;
  }
  
  if ((*node)->value < value) { // if given value is bigger than current node-value go to the right node and check again
    FillSingleValue(&(*node)->right, value);
  }
  else if((*node)->value > value){  //same here just that if value smaller go to left node and check again
    FillSingleValue(&(*node)->left, value);
  }
  return; //if the value is the same, then dont add it
}

void TraverseAndPrintTree(bTreeNode** node) {
  if (!node) {
    printf("\ntree empty\n");
    return;
  } // node has to be checked first, before trying to dereference it for checking actual node pointer
  else if (!(*node)) {
    printf("\ntree empty\n");
    return;
  }

  if ((*node)->left) {   //go left as long as you can
    TraverseAndPrintTree(&(*node)->left);
  }

  printf("value: %d \n", (*node)->value);// when no left node is available print value
  
  if((*node)->right){  //then go one node right and then again to left as long as you can
    TraverseAndPrintTree(&(*node)->right);
  }
}

void AddNode(bTreeNode** headNode, int value) {
  FillSingleValue(headNode, value); // just use the fill SIngeValue Function but with a mir suitable Name
}

bTreeNode* GetNodeWithValue(bTreeNode** node, int valueToFind) { // i dont know what else i should return if someone tries
                                                                // to search for a specific value. because im not sure i'll
                                                                // just return a pointer to the node 🤷‍
  if ((*node)->value > valueToFind) {
    return GetNodeWithValue(&(*node)->left, valueToFind);
  }
  else if ((*node)->value < valueToFind) {
    return GetNodeWithValue(&(*node)->right, valueToFind);
  }

  if ((*node)->value == valueToFind) {
    return (*node);
  }

  return NULL;
}

void deleteTree(bTreeNode** node) {
  if ((*node)->left) {
    deleteNodesFromTree(&((*node)->left));
  }
  if ((*node)->right) {
    deleteNodesFromTree(&((*node)->right));
  }

  printf("deleted value: %d\n", (*node)->value);

  free(*node);
  *node = NULL;
}

void deleteNodesFromTree(bTreeNode** node) {

  if (!node || !(*node)) {
    return;
  }

  if ((*node)->left) {
    deleteNodesFromTree(&(*node)->left);
  }

  if ((*node)->right) {
    deleteNodesFromTree(&(*node)->right);
  }
  printf("deleted value: %d\n", (*node)->value);
  free(*node);
  *node = NULL;
}