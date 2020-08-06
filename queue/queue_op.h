#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

typedef struct mynode{
	char name[MAX];
	int time;
	struct mynode *next;
}node;

node *fr1,*re1,*fr2,*re2;

node* createnode()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}

node* enqueue(node *a,char b[],int t)
{
	node *f;
    	strcpy(a->name,b);
	a->time=t;
    	f=createnode();	
   	a->next=f;
	return f;
}

void dequeue(node *a,int b,int c[])
{
	node *fl;
	int i=0;
	printf("\nQUEUE-%d\n\n",b);
   	printf("JOB_NAME	TIME\n");
	while(a->next!=NULL)
	{
		node *fl;
		fl=a;
		a=a->next;
		c[i]=fl->time;
		printf("%s\t\t%d\n",fl->name,fl->time);
		i++;
		free(fl);
	}
	return;
}

void assign(int a[])
{
    char na[5];
    int ti,t1=0,t2=0,l,co1=0,co2=0,i=1;
	do
	{
		printf("\nJOB-%d\n\n",i);
		printf("enter name:");
		scanf("%s",na);
		printf("enter time:");
		scanf("%d",&ti);
        	printf("\n\n");
		if((t1==t2) || (t1<t2))
		{
			t1+=ti;
			co1++;
			re1=enqueue(re1,na,ti);
		}
		else
		{
			t2+=ti;
			co2++;
			re2=enqueue(re2,na,ti);
		}
		printf("enter 1-continue/0-exit:");
		scanf("%d",&l);
		i++;
	}while(l);
	a[0]=co1;
	a[1]=co2;
	return;
}

void average(int f[])
{
    
	int i,co1,co2;
	float avg,s=0;
    	co1=f[0];
    	co2=f[1];
   	int a[co1],b[co2];
	dequeue(fr1,1,a);
	for(i=0;i<co1;i++)
	{
		s+=a[i];
	}
	avg=s/co1;
	printf("\naverage time:%f\n",avg);
	dequeue(fr2,2,b);
	s=0;
	for(i=0;i<co2;i++)
	{
		s+=b[i];
	}
	avg=s/co2;
	printf("\naverage time:%f",avg);
	return;
}

/*SAMPLE I/O:

ezhil@mypc-inspiron-7572:~/Desktop$ gcc queue.c -o queue
ezhil@mypc-inspiron-7572:~/Desktop$ ./queue

JOB-1

enter name:J1
enter time:6


enter 1-continue/0-exit:1

JOB-2

enter name:J2
enter time:5


enter 1-continue/0-exit:1

JOB-3

enter name:J3
enter time:2


enter 1-continue/0-exit:1

JOB-4

enter name:J4
enter time:3


enter 1-continue/0-exit:1

JOB-5

enter name:J5
enter time:7


enter 1-continue/0-exit:1

JOB-6

enter name:J6
enter time:3


enter 1-continue/0-exit:1

JOB-7

enter name:J7
enter time:7


enter 1-continue/0-exit:1

JOB-8

enter name:J8
enter time:2


enter 1-continue/0-exit:1

JOB-9

enter name:J9
enter time:3


enter 1-continue/0-exit:1

JOB-10

enter name:J10
enter time:7


enter 1-continue/0-exit:0

QUEUE-1

JOB_NAME	TIME
J1		6
J4		3
J6		3
J7		7
J10		7

average time:5.200000

QUEUE-2

JOB_NAME	TIME
J2		5
J3		2
J5		7
J8		2
J9		3

average time:3.800000*/

