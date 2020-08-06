#include<stdio.h>
#include<stdlib.h>

int a[50];
int i=0;

typedef struct treenode *position;
typedef struct treenode searchtree;

struct treenode{
	int element;
	searchtree *left;
	searchtree *right;
};

searchtree* create()
{
	searchtree *t;
	t = (struct treenode*)malloc(sizeof(struct treenode));
	t = NULL;
	return t;
}

searchtree* insert(int x, searchtree* t)
{
	if(t == NULL)
	{
		t = (struct treenode*)malloc(sizeof(struct treenode));
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
void inorder(searchtree *t)
{
	
	if(t!=NULL)
	{
		printf("%d\n",t -> element);
		a[i] = t -> element;
		i++;
		inorder(t->left);
		inorder(t->right);
	}
}

void bst()
{
	int l = 0,m=0,b[50];
	for(int j=0;j<i;j++)
	{
		int l = 0;
		for(int k=0;k<i;k++)
		{
			if(a[j] < a[k])
			{
				l += a[k];
			}
		}
		b[++m] = l;
	}
	printf("greater sum tree: \n");
	for(int j=1;j<=m;j++)
	{
		printf("%d\n",b[j]);
	}
}

int main()
{
	searchtree *s = create();
	s = insert(10,s);
	s = insert(5,s);
	s = insert(15,s);
	s = insert(2,s);
	s = insert(7,s);
	s = insert(12,s);
	s = insert(20,s);
	inorder(s);
	bst();
}
