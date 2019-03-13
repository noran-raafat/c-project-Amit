#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "config.h"
#include "soccer.h"
#include "soccer_types.h"


Players_t Player[PLAYERS_ARRAY_SIZE];
Clubs_t Club[CLUBS_ARRAY_SIZE];



//******* MAIN FUNCTION *******/
void main(void)
{
	char Choice = 0;
	int idd,f,o;
	
	for( f = 0 ; f < PLAYERS_ARRAY_SIZE ; f++ )
	{
		Player[f].ID = -1;   /* IDs initial value */
	}
	for( f = 0 ; f < CLUBS_ARRAY_SIZE ; f++ )
	{
		Club[f].ID = -1;	/* IDs initial value */
		Club[f].num_Goals = 0;
		for( o = 0 ; o < CLUB_PLAYERS ; o++ )
			Club[f].players_ID[o] = -1;		/* IDs initial value */
	}
	while (1)
	{
		system("cls"); // this statement clears the screen
		printf("                   Main Menu\n");
		printf("                   ~~~~~~~~~\n");
		printf("\n\n\t[1]  Add New Player ");
		printf("\n\n\t[2]  Search ");
		printf("\n\n\t[3]  View Statistics ");
		printf("\n\n\t[4]  Exit ");
		printf("\n\n\n\t\tEnter your choice --> ");
		Choice=getch();

		switch (Choice)
		{
		case '1':
			
			addDeleteMenu();
			break;

		case '2':
			
			displayMenu();
			break;

		case '3':
			
			displayStats();
			break;
			
		case '4':
			printf( "\n\n\n GoodBye!!!\n");
			exit(0);

		default:
			printf( "\nInvalid Choice...");
		}

	}

}  // end of main() function





