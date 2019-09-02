#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int e;
	struct node* next;
	struct node* prev;
}n;

void append(n* head)
{
	n* pres=head;
	printf("\nEnter the element : ");
	n* temp=(n*)malloc(sizeof(n));
	int e;
	scanf("%d",&e);
	temp->e=e;
	while(pres->next!=NULL)
	pres=pres->next;
	pres->next=temp;
	temp->prev=pres;
	temp->next=NULL;
}

n* insert_at_position(n* head)
{
	int e,pos;
	n* pres=head;
	printf("Enter the element: ");
	scanf("%d",&e);
	printf("Enter the position: ");
	scanf("%d",&pos);
	n* temp=(n*)malloc(sizeof(n));
	temp->e=e;
	if(pos==1)
	{
		head->prev=temp;
		temp->next=head;
		temp->prev=NULL;
		head=temp;

	}
	/*else if(head==NULL)
	{
		head=temp;
		temp->prev=NULL;
		temp->next=NULL;
	}*/
	else
	{	for(int i=1;i<pos-1;i++)
		pres=pres->next;
		
		temp->next=pres->next;
		
		if(pres->next!=NULL)
		pres->next->prev=temp;
	
		temp->prev=pres;
		pres->next=temp;
		
	}
	return head;
}

n* insert(n* head)
{
	n* temp;
	n* h=head;
	printf("\n\n\t1. Append the element\n\t2. Insert at particular position\n");
	
	if(head==NULL)
	{
		printf("Feature cannot be used as list is empty...\n\nEnter the element for first node: ");
		temp=(n*)malloc(sizeof(n));
		head=temp;
		scanf("%d",&temp->e);
		temp->next=NULL;
		temp->prev=NULL;
		printf("\nNode Inserted!\n");
		return head;
	}
	else
	{
		int n=0;

		while(n!=1 && n!=2){
		printf("\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: append(head);
						break;
			case 2: head=insert_at_position(head);
						break;
			default: printf("Invalid choice! \nPlease try again...\n");
					 break;
		}
	}
	printf("\nNode Inserted!\n");
		return head;
	}
}

void delete_rear(n* head)
{
	n* pres=head;
	if (pres->next==NULL)
	{
		head=NULL;
		free(pres);
	}
	else
	{
		while(pres->next!=NULL)
		pres=pres->next;
		pres->prev->next=NULL;
		free(pres);
	}
}

n* delete_at_position(n* head)
{

	printf("\nEnter the position (using 1-based indexing) : ");
	int pos;
	scanf("%d",&pos);
	n* pres=head;
	if (pos==1)
	{
		head=pres->next;

		if(pres->next!=NULL)
			pres->next->prev=NULL;

		free(pres);
		
		return head;
	}
	else
	{
		for(int i=1;i<pos;i++)
		pres=pres->next;

		pres->prev->next=pres->next;

		if(pres->next!=NULL)
		pres->next->prev=pres->prev;

		free(pres);

		return head;
	}
}

n* delete(n* head)
{
	n* temp;
	n* h=head;
	
	
	if(head==NULL)
	{printf("\n\n\t\tList Empty!\n ");
	return head;}
	
	else
	{
		int n=0;
		printf("\n\n\t1. Delete the last element\n\t2. Delete a particular node\n");
		while(n!=1 && n!=2){
		printf("\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: delete_rear(head);
						break;
			case 2: head=delete_at_position(head);
						break;
			default: printf("Invalid choice! \nPlease try again...\n");
					 break;
		}
		printf("\nNode Deleted!\n");
	}
		return head;
	}
}

void display(n* head)
{
	if(head==NULL)
		printf("\nList Empty!\n");
	else
	{
		printf("\n\n\t\t");
		while(head!=NULL)
		{
			printf("%d <----> ",head->e);
			head=head->next;
		}	
		printf("\n");
	}
}