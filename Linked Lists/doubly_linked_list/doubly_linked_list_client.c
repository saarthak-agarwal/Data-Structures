#include "doubly_linked_list_server.c"
int main()
{
	n* header=NULL;
	int n=1;
	while(n!=5)
	{

		printf("\n\n\t\tOptions:\n\t1. Enter an element\n\t2. Delete an element\n\t3. Sort the elements of the list\n\t4. Display the elements \n\t5. Exit\n");
		printf("\tEnter your choice: ");
		scanf("%d",&n);

		switch(n)
		{
		
			case 1: header=insert(header);
					break;

			case 2: header=delete(header);
					break;
			case 3: header=selection_sort(header);
					display(header);
					break;
			case 4: display(header);
					break;
			case 5: break;
			default: printf("\nInvalid Choice! \n Please try again....\n");
					 break;
		}
		
	}
}