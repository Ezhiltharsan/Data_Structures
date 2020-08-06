#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct mynode
{
	char seat[20];
	struct mynode *next;
}node;

node* insert(int c)
{
	FILE *fptr;
	node *p,*head,*temp;
	int i,j=0;
	char ch[20];
	if(c==1)
	{
		fptr=fopen("today.txt","r");
		p=(node*)malloc(sizeof(node));
		head=p;
		for(i=0;i<10;i++)
		{
			fscanf(fptr,"%s",ch);
			strcpy(p->seat,ch);
			temp=(node*)malloc(sizeof(node));
			p->next=temp;
			p=p->next;
		}
		fclose(fptr);
	}
	else
	{
		fptr=fopen("tom.txt","r");
		p=(node*)malloc(sizeof(node));
		head=p;
		for(i=0;i<10;i++)
		{
			fscanf(fptr,"%s",ch);
			strcpy(p->seat,ch);
			temp=(node*)malloc(sizeof(node));
			p->next=temp;
			p=p->next;
		}
		fclose(fptr);
	}
	return head;
}

node* book_1(node* a,char b[],char c[],int d)
{
	int i;
	node *temp;
	FILE *fptr;
	for(i=0;i<d;i++)
	{
		temp=a;
		while(temp->next!=NULL)
		{
			if(temp->seat[0]==b[i])
			{
				strcat(temp->seat,c);
				break;
			}
			else temp=temp->next;
		}
	}
	return a;
}

node* cancel_1(node *a,char b[],int c)
{
	int i,l;
	node *temp;
	char ch[20];
	for(i=0;i<c;i++)
	{
		temp=a;
		while(temp->next!=NULL)
		{
			if(temp->seat[0]==b[i])
			{
				ch[0]=b[i];
				for(l=1;l<20;l++) ch[l]='\0';
				strcpy(temp->seat,ch);
				break;
			}
			else temp=temp->next;
		}
	}
	return a;
}

void update(node *a,char c[20])
{
	FILE *fptr;
	node *temp;
	temp=a;
	fptr=fopen(c,"w");
	while(temp->next!=NULL)
	{
		fprintf(fptr,"%s\n",temp->seat);
		temp=temp->next;
	}
	fclose(fptr);
}
		
int check(char a[])
{
	FILE *fptr;
	fptr=fopen("login.txt","r");
	int i,co=0,j=0;
	char ch;
	for(i=0;(i<2&&ch!=EOF);i++)
	{
		while((ch=getc(fptr))!='\t')
		{
			if(ch==a[j])
			{
				j++;
				co++;
			}
			else
			{
				while(((ch=getc(fptr))!='\n'))
				{
					if(ch==EOF) 
					{
						fclose(fptr);
						return 0;
					}
					else
					{
						j=0;
						co=0;
					}
				}
			}
		}
		if(co==strlen(a)) 
		{
			fclose(fptr);
			return 1;
		}
	}
	fclose(fptr);
	return 0;
}
	
int check_1(char a[],char b[])
{
	FILE *fptr;
	fptr=fopen("login.txt","r");
	int i,j,n;
	char ch,c[100],d[100];
	while((ch=getc(fptr))!=EOF)
	{
		if(ch=='\t')
		{
			i=0;
			while((ch=getc(fptr))!='\n')
			{
				c[i]=ch;
				i++;
			}
			while(i<=100)
			{
				c[i]='\0';
				i++;
			}
			if((strcmp(a,d)==0)&&(strcmp(b,c)==0)) 
			{
				fclose(fptr);
				return 1;
			}
		}	
		else
		{
			j=0;
			d[j]=ch;
			while((ch=getc(fptr))!='\t')
			{
				j++;
				d[j]=ch;
			}
			while(j<100)
			{
				j++;
				d[j]='\0';
			}
			fseek(fptr,-1,SEEK_CUR);
		}
	}
	fclose(fptr);
	return 0;
}

void checkavailabilty(char a[],char b[])
{
	FILE *fptr;
	fptr=fopen("today.txt","r");
	char c[10];
	int i,j=1,k=1,co=0,co1=0;
	for(i=0;i<10;i++)
	{
		fscanf(fptr,"%s",c);
		{
			if(c[1]<65)
			{
				a[j]=c[0];
				j++;
				co++;
			}
		}
	}
	fclose(fptr);
	fptr=fopen("tom.txt","r");
	for(i=0;i<10;i++)
	{
		fscanf(fptr,"%s",c);
		{
			if(c[1]<65)
			{
				b[k]=c[0];
				k++;
				co1++;
			}
		}
	}
	fclose(fptr);
	while(j<20)
	{
		a[j]='\0';
		j++;
	}
	while(k<20)
	{
		b[k]='\0';
		k++;
	}
	if(co==0) a[0]='n';	
	else a[0]='y';
	if(co1==0) b[0]='n';
	else b[0]='y';
	return;
}


void bookseats(char a[],char b[],int c)
{
	node *p,*p1;
	int j,l,i=0,n;
	char li[20],c1[20],se;
	printf("\nkindly select no of seats\n");
	j=1;
	do
	{
		scanf("%d",&n);
		if(n<strlen(a)) j=0;
		else printf("\nkindly select correct no of seats\n");
	}while(j);
	printf("\nkindly select your seats\n");
	for(j=0;j<n;j++)
	{
		printf("seat-%d:",j+1);
		scanf("\n%c",&se);
		for(l=1;l<strlen(a);l++)
		{
			if(a[l]==se) break;
		}
		if(l<strlen(a))
		{
			li[i]=se;
			i++;
		}
		else 
		{
			printf("kindly select available seats\n");
			j--;
		}
	}
	p=insert(c);
	p=book_1(p,li,b,i);
	if(c==1) update(p,"today.txt");
	else update(p,"tom.txt");
	payment(n);
	return;			
}

void cancel(char a[],int b)
{
	FILE *fptr;
	int i,j=0,n,t=0,l,t1;
	char ch[20],c1[20],se,li[20],c[20];
	node *p;
	if(b==1) fptr=fopen("today.txt","r");
	else fptr=fopen("tom.txt","r");
	for(i=48;i<58;i++)
	{
		ch[0]=i;
		for(t1=1;t1<20;t1++) ch[t1]='\0';
		fscanf(fptr,"%s",c);
		strcat(ch,a);
		if((strcmp(c,ch))==0)
		{
			c1[j]=c[0];
			j++;
		}
	}
	fclose(fptr);
	if(j==0) printf("\nYou don't have any booking on this date\n");
	else
	{
		printf("\nseats booked by you\n");
		for(i=0;i<j;i++) printf("%c ",c1[i]);
		printf("\nkindly select no of seats you want to cancel\n");
		j=1;
		do
		{
			scanf("%d",&n);
			if(n<strlen(c1)) j=0;
			else printf("\nkindly select correct no of seats\n");
		}while(j);
		for(j=0;j<n;j++)
		{
			printf("seat-%d:",j+1);
			scanf("\n%c",&se);
			for(l=0;l<strlen(c1);l++)
			{
				if(c1[l]==se) break;
			}
			if(l<strlen(c1))
			{
				li[t]=se;
				t++;
			}
			else 
			{
				printf("kindly select seats booked by you\n");
				j--;
			}
		}
		p=insert(b);
		p=cancel_1(p,li,t);
		if(b==1) update(p,"today.txt");
		else update(p,"tom.txt");
		printf("\nTickets cancelled successfully\n");
		printf("Refund process is initiated\n");
		printf("You will receive your refund within 7-working days\n");
	}
}

void payment(int a)
{
	int i,age,n;
	char ca[20],cv[20],ot[20],ch[20];
	printf("\nEnter details of passengers\n\n");
	for(i=0;i<a;i++)
	{
		printf("Passenger-%d\n\n",i+1);
		printf("Enter name:");
		scanf("\n%[^\n]",ch);
		printf("Enter age:");
		scanf("\n%d",&age);
		printf("Enter gender(1-M/2-F/3-T):");
		scanf("\n%d",&n);
		printf("\n");
	}
	printf("\nBus Fare Summary\n\n"); 
	printf("Bus Fare\t\t1000\n");
	printf("Taxes   \t\t200\n");
	printf("Total   \t\t1200\n");
	printf("\nTotal Bus Fare\t\t%d.00\n",(1200*a));
	printf("\nPAYMENT GATEWAY\n");
	printf("\nEnter 1-debit card/2-credit card/3-netbanking/4-UPI\n");
	scanf("%d",&i);
	printf("\n");
	if(i==1)
	{
		printf("enter card number:");
		scanf("\n%s",ca);
		printf("enter cvv number:");
		scanf("\n%s",cv);
		printf("\nRedirecting to payment portal\n");
		printf("\nenter OTP:");
		scanf("\n%s",ot);
		printf("\nPayment Processing\n");
	}
	else if(i==2)
	{
		printf("enter card number:");
		scanf("\n%s",ca);
		printf("enter cvv number:");
		scanf("\n%s",cv);
		printf("\nRedirecting to payment portal\n");
		printf("\nenter OTP:");
		scanf("\n%s",ot);
		printf("\nPayment Processing\n");
	}
	else if(i==3)
	{
		printf("enter username:");
		scanf("\n%s",ca);
		printf("enter password:");
		scanf("\n%s",cv);
		printf("\nRedirecting to payment portal\n");
		printf("\nenter OTP:");
		scanf("\n%s",ot);
		printf("\nPayment Processing\n");
	}
	else
	{
		printf("enter UPI password:");
		scanf("\n%s",ca);
		printf("enter UPI pin:");
		scanf("\n%s",cv);
		printf("\nPayment Processing\n");
	}
	printf("\nPayment Successful\n");
	printf("\nTickets have been booked successfully\n\n");
	printf("Thankyou for choosing us\n");
	printf("Wish You A Safe And Happy Journey\n");
	return;
}	
						
