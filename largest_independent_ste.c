#include <stdio.h>
#include <stdlib.h>
int max(int x, int y) 
{
    return (x > y)? x: y; 
    
}
struct node
{
	int data;
	int liss;
	struct node *left, *right;
};

int LISS(struct node *root)
{
	if (root == NULL)
		return 0;

	if (root->liss)
		return root->liss;

	if (root->left == NULL && root->right == NULL)
		return (root->liss = 1);
	int liss_excl = LISS(root->left) + LISS(root->right);
	int liss_incl = 1;
	if (root->left)
		liss_incl += LISS(root->left->left) + LISS(root->left->right);
	if (root->right)
		liss_incl += LISS(root->right->left) + LISS(root->right->right);
	root->liss = max(liss_incl, liss_excl);

	return root->liss;
}
struct node* newNode(int data)
{
	struct node* temp = (struct node *) malloc( sizeof(struct node) );
	temp->data = data;
	temp->left = temp->right = NULL;
	temp->liss = 0;
	return temp;
}
int main()
{
	struct node *root		 = newNode(10);
	root->left			 = newNode(20);
	root->left->left		 = newNode(40);
	root->left->right		 = newNode(50);
		root->right			 = newNode(30);
	root->right->left = newNode(60);
	
	root->right->right	 = newNode(70);
	root->right->right->right = newNode(90);
	root->right->right->left = newNode(80);


	printf ("Size of the Largest Independent Set is %d ", LISS(root));

	return 0;
}
