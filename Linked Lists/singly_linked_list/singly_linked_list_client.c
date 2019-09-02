#include "singly_linked_list_server.c"
int main()
{
	n* header=NULL;
	n* pres=NULL;
	n* temp=NULL;
	int n=1;
	while(n!=4)
	{

		printf("\n\n\t\tOptions:\n\t1. Enter an element\n\t2. Delete an element\n\t3. Display the elements \n\t4. Exit\n");
		printf("\tEnter your choice: ");
		scanf("%d",&n);

		switch(n)
		{
		
			case 1: header=add(header);
					break;

			case 2: header=delete(header);
					break;
			case 3: display(header);
					break;
			case 4: break;
			default: printf("\nInvalid Choice! \n Please try again....\n");
					 break;
		}
		
	}
}