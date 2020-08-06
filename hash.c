#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

struct Record
{
 char data[100];
 struct Record *link;
};

int hash_function(char *key)
{
	int hashval = 0;
 	for(int i = 0; i<strlen(key); i++)
 	{
 		hashval += (key[i])*(i + 1);
 	}
 	return hashval%2069;
}

int search_element(char key[], struct Record *hash_table[])
{
 int h;
 struct Record *ptr;
 h = hash_function(key);
 ptr = hash_table[h];
 while(ptr != NULL)
 {
 if(!strcmp(ptr->data, key))
 {
 return h;
 }
 ptr = ptr->link;
 }
 return -1;
}

void insert(char id[], struct Record *hash_table[])
{
 char key[20];
 int h;
 struct Record *temp;
 strcpy(key,id);
 if(search_element(key, hash_table) != -1)
 {
 printf("Duplicate Key\n");
 return;
 }
 h = hash_function(key);
 temp = malloc(sizeof(struct Record));
 strcpy(temp->data, id);
 temp->link = hash_table[h];
 hash_table[h] = temp;
}

void show(struct Record *hash_table[])
{
 int count;
 struct Record *ptr;
 for(count = 0; count < MAX; count++)
 {
 printf("\n[%3d]", count); 
 if(hash_table[count] != NULL)
 {
 	ptr = hash_table[count];
	 while(ptr->link != NULL)
	 {
	 	printf("%s -> ", ptr->data);
	 	ptr=ptr->link;
	 }
	 printf("%s", ptr->data);
 }
 }
 printf("\n");
}

int main()
{
 struct Record *hash_table[MAX];
 int count;
 char key[20]; 
 int option;
 char id[20];

 for(count = 0; count <= MAX - 1; count++)
 {
 hash_table[count] = NULL;
 }
 while(1)
 {
 printf("\n1. Insert a Record in Hash Table\n");
 printf("2. Show Hash Table\n");
 printf("3. Quit\n");
 printf("Enter your option : ");
 scanf("%d",&option);
 printf("\n");
 switch(option)
 {
 case 1:
 printf("Enter the string : ");
 scanf("%s", id);
 insert(id, hash_table);
 break;
 case 2:
 show(hash_table);
 break;
 case 3:
 exit(1);
 }
 }
 return 0;
}
