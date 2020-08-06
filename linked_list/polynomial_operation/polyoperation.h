#include<stdio.h>
#include<stdlib.h>

typedef struct mynode{
	int co;
	int expo;
	struct mynode *ptr;
}node;

node* add(node *a,node *b,int c,int d)
{
	int i,co1=0,co2=0;
	node *p,*temp,*head,*a1,*b1;
	p=(node*)malloc(sizeof(node));
	head=p;
	a1=a;
	b1=b;
	while(a->ptr!=NULL)
	{
		co1=0;
		b=b1;
		while(b->ptr!=NULL)
		{
			if(a->expo==b->expo)
			{
				p->expo=a->expo;
				p->co=a->co+b->co;
				temp=(node*)malloc(sizeof(node));
				p->ptr=temp;
				p=temp;
            			b=b->ptr;
			}
			else 
			{
				b=b->ptr;
				co1++;
			}
		}
		if(co1==d)
		{
			p->expo=a->expo;
			p->co=a->co;
			temp=(node*)malloc(sizeof(node));
			p->ptr=temp;
			p=temp;
			co2++;
		}
		a=a->ptr;	
	}
	b=b1;
	if(co2==c)
		{
			for(i=0;i<d;i++)
			{
				p->expo=b->expo;
				p->co=b->co;
				temp=(node*)malloc(sizeof(node));
				p->ptr=temp;
				p=temp;
            			b=b->ptr;
				co2++;	
			}
		}
	b=b1;
	while(b->ptr!=NULL)
	{
		co1=0;
		a=a1;
		while(a->ptr!=NULL)
		{
			if(a->expo!=b->expo)
			{
				co1++;
				a=a->ptr;
			}
			else a=a->ptr;
		}
		if(co1==c)
		{
			p->expo=b->expo;
			p->co=b->co;
			temp=(node*)malloc(sizeof(node));
			p->ptr=temp;
			p=temp;
		}
		b=b->ptr;
	}			
	return head;
}

node* multiply(node *a,node *b,int c,int d)
{
	int i,co1;
	node *p,*temp,*head1,*head,*a1,*b1,*p1,*temp1;
	p=(node*)malloc(sizeof(node));
	head1=p;
	a1=a;
	b1=b;
	while(a->ptr!=NULL)
	{
		b=b1;
		while(b->ptr!=NULL)
		{
			p->expo=a->expo+b->expo;
			p->co=a->co*b->co;
			temp=(node*)malloc(sizeof(node));
			p->ptr=temp;
			p=temp;
			b=b->ptr;
		}
		a=a->ptr;	
	}
	p1=head1;
	while(p1->ptr!=NULL)
	{
		temp1=p1;;
		while(temp1->ptr!=NULL)
		{
			if(p1->expo==temp1->ptr->expo)
			{
				p1->expo=p1->expo;
				p1->co=p1->co+temp1->ptr->co;
				temp1->ptr=temp1->ptr->ptr;
			}
			else temp1=temp1->ptr;
		}
		p1=p1->ptr;	
	}
	temp=(node*)malloc(sizeof(node));		
	p=head1;
	while(p->ptr!=NULL)
	{
		p1=p->ptr;
		while(p1->ptr!=NULL)
		{
			if(p->expo<p1->expo)
			{
				temp->expo=p->expo;
				temp->co=p->co;
				p->expo=p1->expo;
				p->co=p1->co;
				p1->expo=temp->expo;
				p1->co=temp->co;
			}
			else p1=p1->ptr;
		}
		p=p->ptr;
	}
	return head1;
}
