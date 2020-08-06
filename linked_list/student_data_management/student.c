#include<stdio.h>
#include"proto.h"

void main()
{
	student stu[5],stu1;
	int i,j,t,s,t1,t2;
	char name1[100];
	for(i=0;i<5;i++)
	{
		printf("enter regno of student.%d:",i+1);
		scanf("\n%d",&stu[i].rollno);
		printf("enter name of student.%d:",i+1);
		scanf("\n%[^\n]",stu[i].name);
		for(j=0;j<5;j++)
		{
			printf("enter subject.%d mark:",j+1);
			scanf("\n%d",&stu[i].marks[j]);
		}
		printf("\n");
	}
	do
	{
		printf("select option to be performed:\n");
		printf("1-insert at first\n2-insert at last\n3-insert at position\n4-serach\n5-delete\n6-display\n7-display before and after\n");
		scanf("%d",&t);
		s=5;
		printf("\n");
		switch (t)
		{
		case 1: printf("enter regno of new student:");
			scanf("\n%d",&stu1.rollno);
			printf("enter name of new student:");
			scanf("\n%[^\n]",stu1.name);
			for(j=0;j<5;j++)
			{
				printf("enter subject.%d mark:",j+1);
				scanf("\n%d",&stu1.marks[j]);
			}
			s=insert1(stu,stu1,s);
			display1(stu,s);
			break;

		case 2:	printf("enter regno of new student:");
			scanf("\n%d",&stu1.rollno);
			printf("enter name of new student:");
			scanf("\n%[^\n]",stu1.name);
			for(j=0;j<5;j++)
			{
				printf("enter subject.%d mark:",j+1);
				scanf("\n%d",&stu1.marks[j]);
			}
			s=insert2(stu,stu1,s);
			display1(stu,s);
			break;

		case 3: printf("enter regno of new student:");
			scanf("\n%d",&stu1.rollno);
			printf("enter name of new student:");
			scanf("\n%[^\n]",stu1.name);
			for(j=0;j<5;j++)
			{
				printf("enter subject.%d mark:",j+1);
				scanf("\n%d",&stu1.marks[j]);
			}
			printf("enter regno to be inserted after:");
			scanf("\n%d",&t1);
			s=insert3(stu,stu1,t1,s);
			display1(stu,s);
			break;

		case 4: printf("enter name to be serached:");
			scanf("\n%[^\n]",name1);
			s=search(stu,name1);
			if(s==1) printf("student is present");
			else printf("student is not present");
			break;

		case 5: printf("enter name of the student to be deleted:");
			scanf("\n%[^\n]",name1);
			s=delete(stu,name1,s);
			display1(stu,s);
			break;

		case 6: display1(stu,s);
			break;

		case 7: printf("enter regno:");
			scanf("%d",&t1);	
			display2(stu,s,t1);
			break;
		}
		printf("enter 1-continue/0-exit:");
		scanf("%d",&t2);	
	}
	while(t2==1);								
}


