//Implementation of Binary search tree, searching, inserting, and deleting node.

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *lptr;
	struct node *rptr;
};

void preOrder(struct node *node)
{
	if(node==NULL)
		return;
	printf("%d ", node -> data);
	if(node -> lptr != NULL)
		preOrder(node -> lptr);
	if(node -> rptr != NULL)
		preOrder(node -> rptr);
}

void postOrder(struct node *node)
{
	if(node==NULL)
		return;
	if(node -> lptr != NULL)
		postOrder(node -> lptr);
	if(node -> rptr != NULL)
		postOrder(node -> rptr);
	printf("%d ", node -> data);
}

void inOrder(struct node *node)
{
	if(node==NULL)
		return;
	if(node -> lptr != NULL)
		inOrder(node -> lptr);
	printf("%d ", node -> data);
	if(node -> rptr != NULL)
		inOrder(node -> rptr);
}

struct node* createNode(int x)
{
	struct node *node;
	node = (struct node*)malloc(sizeof(struct node));
	node->data = x;
	node->lptr = NULL;
	node->rptr = NULL;
	return node;
}

struct node* searchNdInsert(struct node* node, int k)
{
	if (node == NULL)
		return createNode(k);
	if (k < node->data)
		node->lptr = searchNdInsert(node->lptr, k);
	else if (k > node->data)
		node->rptr = searchNdInsert(node->rptr, k);
	return node;
}

//struct node* deleteNode(struct node* node, int x)
//{
//	if (x < node->data)
//		node->left = deleteNode(node -> left, x);
//	else if (x > node->data)
//		node->right = deleteNode(node -> right,x);
//	return node;
//}

int successor(struct node *root) 
{
    root = root -> rptr;
	while (root -> lptr != NULL) 
	{
		root = root -> lptr;
	}
	return root -> data;
}

int predecessor(struct node *root) 
{
	root = root -> lptr;
  	while (root -> rptr != NULL)
	{
		 root = root -> rptr;
	}
  	return root -> data;
}

struct node* deleteNode(struct node *root, int key)
{
	if (root == NULL) 
		return NULL;
  	if (key > root -> data)
	{
		root -> rptr = deleteNode(root -> rptr, key);
	} 
    else if (key < root -> data) 
	{	
		root->lptr = deleteNode(root -> lptr, key);
	}
    else 
	{
		if (root -> lptr == NULL && root -> rptr == NULL) 
			root = NULL;
		else if (root -> rptr != NULL) 
		{
		  	root -> data = successor(root);
		  	root -> rptr = deleteNode(root -> rptr, root -> data);
		} 
		else 
		{
		  	root -> data = predecessor(root);
		  	root -> lptr = deleteNode(root -> lptr, root -> data);
		}
	}
	return root;
}


int main()
{
	struct node* root;

	root = searchNdInsert(root,50);
	searchNdInsert(root, 40);
	searchNdInsert(root, 70);
	searchNdInsert(root, 10);
	searchNdInsert(root, 15);
	searchNdInsert(root, 80);
	searchNdInsert(root, 55);
	searchNdInsert(root, 57);
	searchNdInsert(root, 75);
	searchNdInsert(root, 4);

	searchNdInsert(root, 32);
	searchNdInsert(root, 67);
	searchNdInsert(root, 45);
	searchNdInsert(root, 34);
	searchNdInsert(root, 5);

	printf("Inorder tree: ");
	inOrder(root);
	printf("\nPreorder tree: ");
	preOrder(root);
	printf("\nPostorder tree: ");
	postOrder(root);
	printf("\n");

	deleteNode(root, 50);
	deleteNode(root, 4);
	deleteNode(root, 67);
	printf("After deleting 50, 4, 67 \nPreorder tree: ");
	preOrder(root);
	printf("\n");

	return 0;
}

