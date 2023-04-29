//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//
//#define MAX_SIZE 100
//
//typedef struct node {
//	struct node* next;
//	int data;
//	int size;
//} node;
//
//typedef struct tree {
//	node nodes;
//	struct nodes* input;
//	struct tree* left;
//	struct tree* right;
//	int data;
//} tree;
//
//node* root = NULL;
//int size = 0;
//
//node* insert(node* root, int data)
//{
//	if (root == NULL) {
//		root = (node*)malloc(sizeof(node));
//		root->next = NULL;
//		root->data = data;
//		size++;
//		return root;
//	}
//	else {
//		root->next = insert(root->next, data);
//		return root;
//	}
//}
//
//void preprint(tree* tree) {
//	if (tree) {
//		printf(" [ %d ] ", tree->data);
//		preprint(tree->left);
//		preprint(tree->right);
//	}
//}
//
//int main() {
//	int inputNum = 0;
//	scanf("%d", &inputNum);
//
//	tree bnt[MAX_SIZE];
//
//	for (int i = 1; i <= inputNum; i++) {
//		root = insert(root, i);
//
//		bnt[i].data = root->data;
//		bnt[i].left = NULL;
//		bnt[i].right = NULL;
//
//		root = root->next;
//
//		if (i % 2 == 0) {
//			bnt[i / 2].left = &bnt[i];
//		}
//		else {
//			bnt[i / 2].right = &bnt[i];
//		}
//	}
//
//	preprint(&bnt[1]);
//
//	return 0;
//}