#include<stdio.h>
#include<string.h>
#include"extree_op.h"


void main()
{
	tree *t;
	Stack s=createnode(MAX);
	char exp[MAX],pos[MAX];
	printf("enter expression:");
	scanf("%s",exp);
	postfix(s,exp,pos);
	printf("%s",pos);
	t=construct(pos);
	printf("\ninorder:");
	inorder(t);
	printf("\npreorder:");
	preorder(t);
	printf("\npostorder:");
	postorder(t);
}
