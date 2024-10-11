

#ifndef BTREE_H
#define BTREE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct  node* right;
}node;

node* createNode(int value)
{
	node* newNode = (node*)malloc(sizeof(node));

	if(newNode == NULL)
	{
		printf("Memory allocation failed \n");
		return NULL;
	}
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

node* insert(node* root , int value)
{
	if(root == NULL)
	{
		return createNode(value);

	}
	if(value < root->data)
	{
		root->left = insert(root->left,value);

	}
	else if(value > root->data)
	{
		root->right = insert(root->right,value);
	}
	return root;
}


node* findMin(node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}


node* delete(node* root,int value)
{

	if(root == NULL)
	{
		printf("Value not found in the tree \n");
		return root;
	}

	if( value < root->data)
	{
		root->left = delete(root->left,value);
	}
	else if(value > root->data)
	
	{
		root->right = delete(root->right,value);
	}
	else
	{

		if(root->left == NULL)
		{
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}
		node* temp = findMin(root->right);
		root->data = temp->data;
		root->right = delete(root->right,temp->data);

	}
	return root;
}


node* search(node* root, int value)
{

	if(root == NULL || root->data == value)
		return root;
	if(value < root->data)
		return search(root->left,value);
	return search(root->right,value);
}

void inOrder(node* root)
{

	if(root == NULL)
	{
		return;
	}
	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}


void preOrder(node* root)
{
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node* root)
{

	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
}

#endif



