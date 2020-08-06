#include<stdio.h>
#include<time.h>
#include"file_op.h"

void main()
{
	FILE *fptr;
	int n,i=1,j=1,l,age,num,t=1;
	char ch,gen,a[20],b[20],name[100],user[100],pass[100],se;
	time_t T=time(NULL);
	struct tm tm=*localtime(&T);
	printf("\n\t\t\tEH TRAVELS\n\n");
	printf("\t\t\t\t\t\tHELPLINE:1234567890");
	do
	{
		printf("\n\nenter 1-Login/2-Signup\n");
		scanf("%d",&n);
		if(n==1)
		{
			printf("\nenter username:");
			scanf("\n%[^\n]",user);
			printf("enter password:");
			scanf("\n%[^\n]",pass);
			if(check(user)==1) 
			{
				if(check_1(user,pass)) 
				{
					printf("\n\nWELCOME %s\n",user);
					i=0;
					l=1;
				}
				else printf("\npassword incorrect\n");
			}
			else printf("\nusername incorrect\n");
		}
		else
		{
			fptr=fopen("login.txt","a");
			printf("--SIGN UP DETAILS--\n");
			printf("\nenter your details\n");
			printf("Enter Name:");
			scanf("\n%[^\n]",name);
			printf("Enter Age:");
			scanf("%d",&age);
			printf("Enter Gender(M/F):");
			scanf("\n%c",&gen);
			printf("Enter Ph.No:");
			scanf("%d",&num);
			printf("USERNAME:");
			scanf("\n%[^\n]",user);
			printf("PASSWORD:");
			scanf("\n%[^\n]",pass);
			fprintf(fptr,"%s\t",user);
			fprintf(fptr,"%s\n",pass);
			printf("\nAccount successfully created\n");
			fclose(fptr);
			printf("do you want to continue booking(1-continue/0-exit):");
			scanf("%d",&l);
			i=0;
		}
	}while(i);
	if(l!=0)
	{
		printf("enter 1-ticket booking/2-ticket cancelling:");
		scanf("%d",&l);
		do
		{
			if(l==1)
			{
				printf("\nCHENNAI->MADURAI\n");
				checkavailabilty(a,b);
				if(a[0]=='y'||b[0]=='y') printf("\nAvailable travel dates\n\n");
				if(a[0]=='y') printf("%d/%d/%d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
				if(b[0]=='y')
				{
					if(tm.tm_mon%2==0)
					{
						if(tm.tm_mday+1<32) printf("%d/%d/%d\n",tm.tm_mday+1,tm.tm_mon+1,tm.tm_year+1900);
						else 
						{
							i=tm.tm_mday%31;
							printf("%d/%d/%d\n",i,tm.tm_mon+2,tm.tm_year+1900);
						}
					}
					else
					{
						if(tm.tm_mday+1<31) printf("%d/%d/%d\n",tm.tm_mday+1,tm.tm_mon+1,tm.tm_year+1900);
						else 
						{
							i=tm.tm_mday%30;
							printf("%d/%d/%d\n",i,tm.tm_mon+2,tm.tm_year+1900);
						}
					}
				}
				if(a[0]=='n'&&b[0]=='n')
				{
					printf("\nSorry no buses are available\n");
					break;
				}
				do
				{
					printf("enter 1-continue/0-exit:");
					scanf("%d",&i);
					if(i==1)
					{
						if((a[0]=='y')&&(b[0]=='y'))
						{
							printf("enter 1-today/2-tomorrow:");
							scanf("%d",&n);
							if(n==1)
							{
								printf("\nAvailable seats\n");
								for(l=1;l<strlen(a);l++)
								{
									printf("%c  ",a[l]);
								}
								bookseats(a,user,1);
								j=0;
							}
							else if(n==2)
							{
								printf("\nAvailable seats\n");
								for(l=1;l<strlen(b);l++)
								{
									printf("%c  ",b[l]);
								}
								bookseats(b,user,2);
								j=0;
							}
						}
						else if(a[0]=='y')
						{
							printf("\ntoday\n");
							printf("\nAvailable seats\n");
							for(l=1;l<strlen(a);l++)
							{
								printf("%c  ",a[l]);
							}
							bookseats(a,user,1);
							j=0;
						}
						else if(b[0]=='y')
						{
							printf("\ntomorrow\n");
							printf("\nAvailable seats\n");
							for(l=1;l<strlen(b);l++)
							{
								printf("%c  ",b[l]);
							}
							bookseats(b,user,2);
							j=0;
						}
						else printf("\nkindly select today/tomorrow\n");
					}
					else j=0;
				}while(j);
				t=0;
			}
			else if(l==2)
			{
				printf("enter 1-today/2-tomorrow:");
				scanf("%d",&j);
				cancel(user,j);
				t=0;
			}
			else printf("kindly select the given option");
		}while(t);
	}
}
