#include "singly_linked_list_server.c"
int main()
{
	n* header=NULL;
	int n=1;
	while(n!=6)
	{

		printf("\n\n\t\tOptions:\n\t1. Enter an element\n\t2. Delete duplicate element\n\t3. Delete an element\n\t4. Sort the elements of the list\n\t5. Display the elements \n\t6. Exit\n");
		printf("\tEnter your choice: ");
		scanf("%d",&n);

		switch(n)
		{
		
			case 1: header=add(header);
					break;
			case 2: delete_multiple_occurences(header);
					break;

			case 3: header=delete(header);
					break;
			case 4: header=selection_sort(header);
					display(header);
					break;
			case 5: display(header);
					break;
			case 6: break;
			default: printf("\nInvalid Choice! \n Please try again....\n");
					 break;
		}
		
	}
}
