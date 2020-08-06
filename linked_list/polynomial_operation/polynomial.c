#include<stdio.h>
#include"polyoperation.h"

void main()
{
    int i,n,n1,n2;
	node *temp,*p,*head2,*head3,*head1;
	p=(node*)malloc(sizeof(node));
	head1=p;
	printf("enter no of terms:");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
			printf("enter exponent:");
			scanf("%d",&p->expo);
			printf("enter coefficient:");
			scanf("%d",&p->co);
			temp=(node*)malloc(sizeof(node));
			p->ptr=temp;
			p=temp;
	}
    p=(node*)malloc(sizeof(node));
    head2=p;
    printf("enter no of terms:");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("enter exponent:");
        scanf("%d",&p->expo);
        printf("enter coefficient:");
        scanf("%d",&p->co);
        temp=(node*)malloc(sizeof(node));
        p->ptr=temp;
        p=temp;
    }
    printf("enter 1-add/2-multiply");
    scanf("%d",&n);
    if(n==1) head3=add(head1,head2,n1,n2);
    else head3=multiply(head1,head2,n1,n2);
	printf("Polynomial A\n\n:");
	temp=head1;
	while(temp->ptr!=NULL)
    {
	printf("exponent	coefficient:%d	%d\n",temp->expo,temp->co);
	temp=temp->ptr;
    }
	printf("Polynomial B\n\n:");
	temp=head2;
	while(temp->ptr!=NULL)
    {
	printf("exponent	coefficient:%d	%d\n",temp->expo,temp->co);
	temp=temp->ptr;
    }

    temp=head3;
    printf("result:\n");
    while(temp->ptr!=NULL)
    {
	printf("exponent	coefficient:%d	%d\n",temp->expo,temp->co);
	temp=temp->ptr;
    }
}
