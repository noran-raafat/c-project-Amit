#include <stdio.h>

void main (void)
{
	char c;   /* user's choice */
	char exitFlag =0 ; 
	
	do
	{
	
		printf("Welcome!");
		printf("\nPlease select an option:");
		printf("\n1 Enter new player");
		printf("\n2 View Stats");
		printf("\n3 Search");
		printf("\n4 Exit\n");
		
		scanf("%d",&c);
		switch (c)
		{
			case 1:
			{
				/* Go to file 2 (meaning function in file 2) */
				printf("option 1");
				break;
			}
			case 2: 
			{
				/* Go to file 3 */
				printf("option 2");
				break;
			}
			case 3: 
			{
				/* Go to file 4 */
				printf("option3");
				break;
			}
			case 4:
			{
				exitFlag = 1;
				break;
			}
			default :
			{
				printf("Please enter: 1 or 2 or 3 or 4 to choose an option");
			}
		}
	}while(exitFlag == 0);
}


