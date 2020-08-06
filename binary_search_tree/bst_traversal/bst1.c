#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct mytree{
	char name[100];
	struct mytree *left;
	struct mytree *right;
}tree;

tree* construct(tree *a)
{
	tree *b=a;
	char na[100]; 
	int i=1;
	do
	{
		printf("enter name:");
		scanf("\n%[^\n]",na);
		while(i)
		{
			if(strcmp(a->name,na)>0)
			{
				if(a->left==NULL)
				{
					a->left=(tree*)malloc(sizeof(tree));
					strcpy(a->left->name,na);
					i=0;
				}
				else a=a->left;
			}
			else
			{
				if(a->right==NULL)
				{
					a->right=(tree*)malloc(sizeof(tree));
					strcpy(a->right->name,na);
					i=0;
				}
				else a=a->right;
			}
		}
		a=b;
		printf("enter 1-continue/0-exit:");
		scanf("%d",&i);
	}while(i);
	return b;
}

void inorder(tree *a)
{
	if(a!=NULL)
	{
		inorder(a->left);
		printf("%s\n",a->name);
		inorder(a->right);
	}
}

void grandparent(tree *a,char n[])
{
	if(a!=NULL)
	{
		grandparent(a->left,n);
		if(a->left!=NULL)
		{
			if(a->left->left!=NULL) if(strcmp(a->left->left->name,n)==0) printf("%s\n",a->name);
			else if(a->left->right!=NULL) if(strcmp(a->left->right->name,n)==0) printf("%s\n",a->name);
		}
		else if(a->right!=NULL)
		{
			if(a->right->left!=NULL) if(strcmp(a->right->left->name,n)==0) printf("%s\n",a->name);
			else if(a->right->right!=NULL) if(strcmp(a->right->right->name,n)==0)  printf("%s\n",a->name);
		}
		grandparent(a->right,n);
	}
}
	
void grandchildren(tree *a,char n[])
{
	if(a!=NULL)
	{
		grandchildren(a->left,n);
		if(strcmp(a->name,n)==0)
		{
			if(a->left!=NULL)
			{
			if(a->left->left!=NULL)  printf("%s\n",a->left->left->name);
			if(a->left->right!=NULL)  printf("%s\n",a->left->right->name);
			}
		if(a->right!=NULL)
			{
			if(a->right->left!=NULL)  printf("%s\n",a->right->left->name);
			if(a->right->right!=NULL)  printf("%s\n",a->right->right->name);
			}
		}
		grandchildren(a->right,n);
	}
}

void sibling(tree *a,char n[])
{
	if(a!=NULL)
	{
		sibling(a->left,n);
		if(a->left!=NULL) if(strcmp(a->left->name,n)==0) if(a->right!=NULL) printf("%s\n",a->right->name);
		else if(a->right!=NULL) if(strcmp(a->right->name,n)==0) if(a->left!=NULL) printf("%s\n",a->left->name);
		sibling(a->right,n);
	}
}

tree* findmin(tree *a)
{
	if(a==NULL) return NULL;
	else if(a->left==NULL) return a;
	else return findmin(a->left);
}
tree* delete(tree *a,char n[])
{
	tree *temp;
	if(strcmp(a->name,n)>0) a->left=delete(a->left,n);
	else if(strcmp(n,a->name)>0) a->right=delete(a->right,n);
	else if(a->left&&a->right)
	{
		temp=findmin(a->right);
		strcpy(a->name,temp->name);
		a->right=delete(a->right,a->name);
	}
	else
	{
		temp=a;
		if(a->left==NULL) a=a->right;
		else if(a->right==NULL) a=a->left;
		free(temp);
	}
	return a;
}
			
void main()
{
	char na[100];
	tree *t,*t1;
	int i;
	t=(tree*)malloc(sizeof(tree));
	printf("enter name:");
	scanf("%[^\n]",na);
	strcpy(t->name,na);
	printf("enter 1-continue/0-exit:");
	scanf("%d",&i);
	if(i==1) t=construct(t);
	t1=t;
	inorder(t);
	do
	{
		printf("enter 1-grand parent/2-grand children/3-sibling:");
		scanf("%d",&i);
		t=t1;
		switch(i)
		{
			case 1: printf("enter name:");
				scanf("\n%[^\n]",na);
				grandparent(t,na);
				break;
			case 2: printf("enter name:");
				scanf("\n%[^\n]",na);
				grandchildren(t,na);
				break;
			case 3: printf("enter name:");
				scanf("\n%[^\n]",na);
				sibling(t,na);
		}
		printf("enter 1-continue/0-exit:");
		scanf("%d",&i);
	}while(i);
	printf("enter name to be deleted:");
	scanf("\n%[^\n]",na);
	t=t1;
	t1=delete(t,na);
	inorder(t1);
}
