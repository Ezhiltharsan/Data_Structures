#include<stdio.h>
#include<stdlib.h>

int i=0;

typedef struct treenode{
	int element;
	struct treenode *left;
	struct treenode *right;
}tree;

tree* create()
{
	tree *t;
	t = (tree*)malloc(sizeof(tree));
	t = NULL;
	return t;
}

tree* insert(int x, tree* t)
{

	if(t == NULL)
	{
		t = (tree*)malloc(sizeof(tree));
		if(t == NULL)
			printf("out of space\n");
		else
		{
			t->element=x;
			t->left = t->right = NULL;
		}
	}
	else 
	{
		if(t->element>x)
			t->left=insert(x,t->left);
		else
			t->right=insert(x,t->right);
	}
	return t;
}
void inorder(tree *t,int a[])
{
	if(t!=NULL)
	{
		inorder(t->left,a);
		a[++i] = t -> element;
		inorder(t->right,a);
	}
}

int bst(int a[])
{
	for(int j=0;j<i-1;j++)
	{
		if(a[j] > a[j+1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int a[50];
	tree *s = create();
	s = insert(10,s);
	s = insert(5,s);
	s = insert(15,s);
	s = insert(2,s);
	s = insert(7,s);
	s = insert(12,s);
	s = insert(20,s);
	inorder(s,a);
	if(bst(a) == 1)
		printf("the tree is bst\n");
	else
		printf("the tree is not a bst\n");
}
