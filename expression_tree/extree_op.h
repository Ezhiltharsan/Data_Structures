#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define maxno 100
#define start -1
#define MAX 100

typedef struct 
{
	int *stack;
	int top,max;
}Stack;

typedef struct mytree
{
	char c;
	struct mytree *right,*left;
}tree;

typedef struct
{
	tree *arr[100];
	int top,max;
}sta;

Stack createnode(int size)
{
	Stack s;
	s.top=start;
	s.max=maxno;
	if(size<=s.max)
	{
		s.stack=(int*)malloc(sizeof(int)*size);
	}
	return s;
}

int isEmpty(Stack s)
{
	return s.top == start;
}

void pop(Stack *s)
{
	if(isEmpty(*s))
		printf("EMPTY STACK\n");
	else
		s->top--;
    return;
}

void postfix(Stack s,char t[],char p[])
{
	if(isEmpty(s))
	{	int k=0;
		for(int i=0;i<strlen(t);i++)
		{
			if(isdigit(t[i]))
				p[k++]=t[i];
			else
			{	if(s.stack[s.top]=='*' && (t[i]!='(' && t[i]!=')' ) )
				{
					p[k++]=s.stack[s.top];
					pop(&s);
				}
				s.stack[++s.top]=t[i];
				if(s.stack[s.top]==')')
				{	char x;
					while(s.stack[s.top]!='(')
					{	x=s.stack[s.top];
						pop(&s);
						if(x!=')')
							p[k++]=x;
					}
					pop(&s);
				}
			}
		}
		if(!isEmpty(s))
		{	while(s.top!=-1)
			{
				p[k++]=s.stack[s.top];
				pop(&s);
			}
		}
		p[k]='\0';
	}
    return;
}

int operator(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^') return 1;
	return 0;
}
/*
tree* construct(char exp[])
{
	tree *t,*temp,*p,*t1,*t2;
	int i;
	Stack s;
	s=createnode(MAX);
	p=(tree*)malloc(sizeof(tree));
	for(i=0;i<strlen(exp);i++)
	{
		if(operator(exp[i])==1)
		{
			p->c=exp[i];
			if(t1->c==s.stack[(s.top-1)] || t2->c==s.stack[(s.top)])
			{
				p->left=t1;
				p->right=t2;
				pop(&s);
				pop(&s);
				//s.stack[s.top]=exp[i];
				t1=p;
			}
			else if(t1->c==s.stack[(s.top)])
			{
				p->left=t1;
				temp=(tree*)malloc(sizeof(tree));
				p->right=temp;
				p->right->c=s.stack[s.top];
				pop(&s);
				//s.stack[s.top]=exp[i];
				t1=p;
			}
			else
			{	
				temp=(tree*)malloc(sizeof(tree));
				p->right=temp;
				temp->c=s.stack[s.top];
				pop(&s);
				temp=(tree*)malloc(sizeof(tree));
				p->left=temp;
				temp->c=s.stack[s.top];
				pop(&s);
				//s.stack[s.top++]=exp[i];
				if(!isEmpty(s))
				{
					if(isdigit(s.stack[s.top])&&isdigit(s.stack[s.top-1]&&operator(s.stack[s.top-2]))) t2=p;
					else t1=p;
					temp=(tree*)malloc(sizeof(tree));
					p=temp;
				}
			}
			
			if(i!=strlen(exp)-1) s.stack[s.top++]=exp[i];
			/*
			else
			{
				p->c=exp[i];
				temp=(tree*)malloc(sizeof(tree));
				
				if(i==(strlen(exp)-1))
				{
					temp=(tree*)malloc(sizeof(tree));
					temp->left=p;
			*//*
		}
		else s.stack[++s.top]=exp[i];
	}
	if(!isEmpty) 
	{
		t2->left=t1;
		return t2;
	}
	return p;
	
}*/
void push(sta *a,tree *b)
{
	a->arr[++(a->top)]=b;
	return;
}

void pop_1(sta *a)
{
	a->top--;
	return;
}


tree* newNode(char v) 
{ 
	tree* temp ;
	temp= (tree*)malloc(sizeof(tree));
	temp->c = v; 
	return temp; 
}

tree* construct(char postfix[]) 
{ 
	sta *st; 
	st=(sta*)malloc(sizeof(sta));
	st->top=-1;
	tree *t,*t1,*t2; 
	for (int i=0; i<strlen(postfix); i++)
	{ 
		if (!operator(postfix[i])) 
		{ 
			t = newNode(postfix[i]); 
			push(st,t); 
		} 
		else 
		{ 
			t = newNode(postfix[i]); 
			t1 = st->arr[st->top]; 
			pop_1(st); 
			t2 = st->arr[st->top]; 
			pop_1(st); 
			t->right = t1;
			t->left = t2;
			push(st,t);
		} 
	} 
	(st->arr[st->top]); 
	pop_1(st); 
	return t; 
}

void inorder(tree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%c",t->c);
		inorder(t->right);
	}
}	

void preorder(tree *t)
{
	if(t!=NULL)
	{
		printf("%c",t->c);
		preorder(t->left);
		preorder(t->right);
	}
}

void postorder(tree *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%c",t->c);
	}
}
			
			
		

