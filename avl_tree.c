#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct avlnode{
	char ta[100];
	char en[100];
	char hi[100];
	struct avlnode *left;
	struct avlnode *right;
	int he;
}avl;

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int height(avl *a)
{
	if(a==NULL) return -1;
	else return a->he;
}

avl* single_right(avl *l)
{
    printf("\nRIGHT ROTATION\n");
    avl *a;
    a=(avl*)malloc(sizeof(avl));
    a=l->right;
    l->right = a->left;
    a->left = l;
    l->he = max(height(l->left),height(l->right))+1;
    a->he = max(height(a->left),height(a->right))+1;
    return a;
}

avl* single_left(avl *l)
{
    printf("\nLEFT ROTATION\n");
    avl *a;
    a=(avl*)malloc(sizeof(avl));
    a=l->left;
    l->left=a->right;
    a->right=l;
    l->he=max(height(l->left),height(l->right))+1;
    a->he=max(height(a->left),height(a->right))+1;
    return a;
}

avl* double_leftright(avl *l)
{
    printf("\nDouble rotation with left and right\n");
    l->left = single_right(l->left);
    return single_left(l);
}

avl* double_rightleft(avl *l)
{
    printf("\nDouble rotation with right and left\n");
    l->right = single_left(l->right);
    return single_right(l);
}

avl* insert(char a[],char b[],char c[],avl *t)
{
	if(t==NULL)
	{
		t=(avl*)malloc(sizeof(avl));
		strcpy(t->ta,a);
		strcpy(t->en,b);
		strcpy(t->hi,c);
		t->he=0;
	}
	else if(strcmp(t->en,b)>0)
	{
		t->left=insert(a,b,c,t->left);
		if(height(t->left)-height(t->right)==2)
		{
			if(strcmp(t->left->en,b)>0) t=single_left(t);
			else t=double_leftright(t);
		}
	}
	else if(strcmp(b,t->en)>0)
	{
		t->right=insert(a,b,c,t->right);
		if(height(t->right)-height(t->left)==2)
		{
			if(strcmp(b,t->right->en)>0) t=single_right(t);
			else t=double_rightleft(t);
		}
	}
	t->he=max(height(t->left),height(t->right))+1;
	return t;
}

void inorder(avl *a)
{
	if(a!=NULL)
	{
		inorder(a->left);
		printf("%s\n",a->ta);
		printf("%s\n",a->en);
		printf("%s\n",a->hi);
		inorder(a->right);
	}
}

void search(avl *a,char b[])
{
	if(a!=NULL)
	{
		search(a->left,b);
		if(strcmp(a->en,b)==0)
		{
			printf("tamil meaning:%s\n",a->ta);
			printf("hindi meaning:%s\n",a->hi);
		}
		search(a->right,b);
	}
}

void main()
{
	avl *t=NULL;
	int n;
	char na1[100],na2[100],na3[100];
	do
	{
		printf("Enter 1-Insert/2-Search:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:  printf("Enter English word:");
				 scanf("\n%[^\n]",na2);
				 printf("Enter tamil word:");
				 scanf("\n%[^\n]",na1);
				 printf("Enter hindi word:");
				 scanf("\n%[^\n]",na3);
				 t=insert(na1,na2,na3,t);
                inorder(t);
                printf("\n");
				 break;
			case 2: printf("Enter word:");
				scanf("\n%[^\n]",na1);
				search(t,na1);
		}
		printf("enter 1-continue/0-exit:");
		scanf("%d",&n);
	}while(n);
}
