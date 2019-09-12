#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int e;
	struct node* next;
}n;

void append(n* temp, n* head)
{
	n* p=head;
	printf("\nEnter the element to be inserted: ");
	scanf("%d",&temp->e);
	while(p->next!=NULL)
	p=p->next;
	p->next=temp;
}

n* insert_at_position(n* temp, n* head)
{
	n* p=head;
	int n=0;
	printf("\nEnter the element to be inserted: ");
	scanf("%d",&temp->e);
	printf("Enter the position: ");
	scanf("%d",&n);
	if(n==1)
	{
		temp->next=head;
		head=temp;

	}
	else{
	for(int i=1;i<n-1;i++)
	{
		p=p->next;
	}
	temp->next=p->next;
	p->next=temp;
}
return head;
}

n* add(n* head)
{
	n* temp;
	n* h=head;
	printf("\n\n\t1. Append the element\n\t2. Insert at particular position\n");
	temp=(n*)malloc(sizeof(n));
	temp->next=NULL;
	
	if(head==NULL)
	{
		printf("Feature cannot be used as list is empty...\n\nEnter the element for first node: ");
		head=temp;
		scanf("%d",&temp->e);
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
			case 1: append(temp,head);
						break;
			case 2: head=insert_at_position(temp,head);
						break;
			default: printf("Invalid choice! \nPlease try again...\n");
					 break;
		}
	}
	printf("\nNode Inserted!\n");
		return head;
	}
}

n* delete_rear(n* head)
{
	n* pres=head;
	if (pres->next==NULL)
	{
		head=NULL;
		free(pres);
	}
	else
	{
		while(pres->next->next!=NULL)
		pres=pres->next;
		free(pres->next);
		pres->next=NULL;
	}
	return head;
}

n* delete_at_position(n* head)
{

	printf("\nEnter the position (1-based indexing) : ");
	int pos;
	n* temp;
	scanf("%d",&pos);
	n* pres=head;
	if (pos==1)
	{
		head=pres->next;
		free(pres);
	}
	else
	{
		for(int i=1;i<pos-1;i++)
		pres=pres->next;
		temp=pres->next;
		pres->next=pres->next->next;
		free(temp);
		
	}
	return head;
}

n* delete(n* head)
{
	n* temp;
	n* h=head;
	
	if(head==NULL)
	{
		printf("\n\n\t\tList Empty!\n ");
		return head;
	}
	
	else
	{
		int n=0;
		printf("\n\n\t1. Delete the last element\n\t2. Delete a particular node\n");
		while(n!=1 && n!=2){
		printf("\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: head=delete_rear(head);
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

void display(n* h)
{
	if(h==NULL)
		printf("\n\t\tList is Empty!\n");
	else
	{
		printf("\n\n");
		while(h!=NULL)
		{
			printf("%d\t-->\t",h->e );
			h=h->next;
		}
		printf("\n\n");
	}
}

n* selection_sort(n* head)
{
	int min=99999999;
	n* pres=head;
	n* temp=NULL;
	int t=0;
	
	if(head!=NULL)
	{
		for(n* i=head;i->next!=NULL;)
		{
			min=i->e;
			for( n* j=i->next;j!=NULL;)
			{

				if(j->e<min)
				{
					min=j->e;
					temp=j;
				}
				
				j=j->next;
			}
			if(min!=i->e)
			{
				t=temp->e;
				temp->e=i->e;
				i->e=t;
			}
			i=i->next;
		}
	}
	return head;
}

void delete_multiple_occurences(n* head)
{
	n* temp=NULL;
	n* prev=NULL;
	n* p=head;	
	n* q=NULL;	
	if(head==NULL)
	printf("\n\t\tList Empty!\n");
	else
	{
		while(p!=NULL)
		{
			prev=p;
			q=p->next;
			while(q!=NULL)
			{
				int c=0;
				if(p->e==q->e)
				{
					c=1;
					temp=q;
					prev->next=q->next;
				}
				if(c==0)
				prev=q;
				q=q->next;
				if(c==1)
				free(temp);
			}			
			p=p->next;
		}
	printf("\n\t\tDuplicate elements deleted!\n");
	}
	
}

