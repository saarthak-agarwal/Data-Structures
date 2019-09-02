#include "doubly_linked_list_server.c"
int main()
{
	n* head=NULL;
	int n=0;
	while(n!=4)
	{

		printf("\n\n\t\tOptions:\n\t1. Enter an element\n\t2. Delete an element\n\t3. Display the elements \n\t4. Exit\n");
		printf("\tEnter your choice: ");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1: head=insert(head);
					break;
			case 2: head=delete(head);
					break;
			case 3: display(head);
					break;
			case 4: break;
			default: printf("\n\nInvalid choice!\nPlease try again...\n");
					 break; 
		}
			
	}
}