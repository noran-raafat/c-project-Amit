#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "config.h"
#include "soccer_types.h"
#include "soccer.h"

extern Players_t Player[PLAYERS_ARRAY_SIZE];
extern Clubs_t Club[CLUBS_ARRAY_SIZE];

void displayMenu()
{
	calcStats();
	
	while(1)
	{
		char Entry;
		system("cls");
		printf("                Display Menu\n");
		printf("                ~~~~~~~~~~~~\n");
		printf("\n\n\t[1]  Display All Players");
		printf("\n\n\t[2]  Display All Clubs ");
		printf("\n\n\t[3]  Search for a Player");
		printf("\n\n\t[4]  Search for a Club");
		printf("\n\n\t[5]  Return to the Main Menu");
		printf("\n\n\n\t\tEnter your choice --> ");
		Entry = getch();
		switch (Entry)
		{
			case '1':
					displayAllPlayer();
					break;
			case '2':
					displayAllClub();
					break;
			case '3':
					searchForPlayerMenu();
					break;
			case '4':
					searchForClubMenu();
					break;
			case '5':
					return;
			default:
					printf( "\nInvalid Choice...");
				
		}
	}
}

void displayAllPlayer()
{
	system("cls");
	int c,i;
	i=0;
	for( c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++ )
	{
		if( Player[c].ID != -1 )
		{
			printf(" Name: %s \n Weight: %d \n Height: %f \n Defense: %f % \n Number Of Goals: %d \n Speed: %f \n Assists: %f \n Rank: %f \n Club: %s\n", Player[c].name , Player[c].weight , Player[c].height , Player[c].defense , Player[c].num_Goals , Player[c].speed , Player[c].assist , Player[c].rank ,Club[Player[c].club_ID].name);
			printf("\n~~~~~~~~~~~~~~~~~~~~~\n");
			i++;
			
		}
	}
	if( i != 0 )
	{
		printf("There are %d Players\n" ,i );
		system("pause");
		return;
	}
	printf("NO PLAYERS\n");
	
	system("pause");
}

void displayAllClub()
{
	system("cls");
	char c,i,g,x=0;
	calcStats();
	for( c = 0 ; c < CLUBS_ARRAY_SIZE ; c++ )
	{
		if(Club[c].ID != -1)
		{
			printf("--------------------"); 
			printf("\n\n\n Name: %s \n Number Of Goals: %d \n Rank: %f\n" , Club[c].name , Club[c].num_Goals , Club[c].rank);
			printf(" ~~~~~~~~ Team Members ~~~~~~~~\n\n");
			for( i = 0 ; i < CLUB_PLAYERS ; i++)
			{
				g = Club[c]. players_ID[i];
				//printf("Players ID = %d",Club[c].players_ID[i]);
				if(g != -1)
				{
					printf(" %d - %s \n", i+1 , Player[g].name);
				}
			}
			x++;
		}
	}
	if(x != 0)
	{
		printf("\nThere are %d Clubs\n" ,x );
		system("pause");
		return;
	}
	printf("NO Clubs");
	
	system("pause");

}


void searchForPlayerMenu()
{
	while(1)
	{
		char Entry;
		char id = 0;
		system("cls");
		printf("                Filters Menu\n");
		printf("                ~~~~~~~~~~~~\n");
		
		printf("\n\n\t[1]  Search by Name ");
		printf("\n\n\t[2]  Search by Rank ");
		
		printf("\n\n\t[3]  Search by Height  ");
		printf("\n\n\t[4]  Search by Weight  ");
		
		printf("\n\n\t[5]  Search by Number of Goals  ");
		printf("\n\n\t[6]  Search by Defense  ");
		printf("\n\n\t[7]  Search by Speed  ");
		printf("\n\n\t[8]  Search by Assist  ");

		printf("\n\n\t[9]  Return to the Main Menu");
		printf("\n\n\n\t\tEnter your choice --> ");
		Entry = getch();
		switch (Entry)
		{
			case '1':
					id=searchPlayerName();
					printPlayerID(id);
					system("pause");
					break;
			case '2':
					id=searchPlayerRank();
					printPlayerID(id);
					system("pause");
					break;		
			case '3':
					searchPlayerHeight();
					system("pause");
					break;
			case '4':
					searchPlayerWeight();
					
					system("pause");
					break;
			case '5':
					searchPlayerNumGoals();
					system("pause");
					break;
			case '6':
					searchPlayerDefense();
					system("pause");
					break;
			case '7':
					searchPlayerSpeed();
					system("pause");
					break;
					return;
			case '8':
					searchPlayerAssist();
					system("pause");
					break;
					return;
			case '9':
					return;

					
			default:
					printf( "\nInvalid Choice...");
				
		}
	}
}

int searchPlayerName()
{
	char KEY[NAME_SIZE];
	char c,p;
	char found = 0;
	printf("\nEnter The Player's Name: ");
	scanf("%s",&KEY);
	for(p = 0 ; p < PLAYERS_ARRAY_SIZE ; p++)
	{
		while(KEY[c] != '\0')
		{
			/*printf("\n%c",Player[p].name[c]);
			printf("\n%c",KEY[c]);
			*/
			if(Player[p].name[c] == KEY[c])
			{

				found++;
				printf("%d",found);

			}
			c++;
		}
		if(found == c)
		{
			return p;
		}
		/*
		if(Player[p].name == KEY)
			{
				found++;
				break;

			}
			*/
		
	}
	/*
	if(found)
	{
		return p;
	}
	*/
	
	
	return -1;
			
	
}

int searchPlayerRank()
{
	int KEY;
	char c;
	char found = 0;
	printf("Enter The Player's Rank: ");
	scanf("%d",&KEY);
	for(c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++)
	{
		if(Player[c].rank == KEY)
		{
			found = 1;
			break;
		}
	}
	if(found)
	{
		return c;
	}
	return -1;
}

void searchPlayerDefense()
{
	float KEY1,KEY2;
	char c;
	char found = 0;
	printf("\nThe Player's Defencse is greater than: ");
	scanf("%f",&KEY1);
	printf("\nThe Player's Defence is less than: ");

	scanf("%f",&KEY2);
	for(c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++)
	{
		if((Player[c].defense >= KEY1) && (Player[c].defense <= KEY2))
		{
			found = 1;
			printPlayerID(c);
		}
	}
	if(found)
	{
		return;
	}
	printf("There are no players with defense in this range");
}

void searchPlayerHeight()
{
	float KEY1,KEY2;
	char c;
	char found = 0;
	printf("\nThe Player's Height is greater than: ");
	scanf("%f",&KEY1);
	printf("\nThe Player's Height is less than: ");

	scanf("%f",&KEY2);
	for(c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++)
	{
		if((Player[c].height >= KEY1) && (Player[c].height <= KEY2))
		{
			found = 1;
			printPlayerID(c);
		}
	}
	if(found)
	{
		return;
	}
	else 
	{
		printf("There are no players with height in this range");

	}
}
	

void searchPlayerWeight()
{
	float KEY1,KEY2;
	char c;
	char found = 0;
	printf("\nThe Player's Weight is greater than: ");
	scanf("%d",&KEY1);
	printf("\nThe Player's Weight is less than: ");

	scanf("%d",&KEY2);
	for(c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++)
	{
		if((Player[c].weight >= KEY1) && (Player[c].weight <= KEY2))
		{
			found = 1;
			printPlayerID(c);
		}
	}
	if(found)
	{
		return;
	}
	printf("There are no players with weight in this range");
}

void searchPlayerSpeed()
{
	float KEY1, KEY2;
	char c;
	char found = 0;
	printf("\nThe Player's Speed is greater than: ");
	scanf("%f",&KEY1);
	printf("\nThe Player's Speed is less than: ");

	scanf("%f",&KEY2);
	for(c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++)
	{
		if((Player[c].speed >= KEY1) && (Player[c].speed <= KEY2))
		{
			found = 1;
			printPlayerID(c);
		}
	}
	if(found)
	{
		return;
	}
	printf("There are no players with speed in this range");
}

void searchPlayerNumGoals()
{
	float KEY1,KEY2;
	char c;
	char found = 0;
	printf("\nThe Player's Number of Goals is greater than: ");
	scanf("%f",&KEY1);
	printf("\nThe Player's Number of Goals is less than: ");

	scanf("%f",&KEY2);
	for(c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++)
	{
		if((Player[c].num_Goals >= KEY1) && (Player[c].num_Goals <= KEY2))
		{
			found = 1;
			printPlayerID(c);
		}
	}
	if(found)
	{
		return;
	}
	printf("There are no players with number of goals in this range");
}

			
void searchPlayerAssist()
{
	float KEY1,KEY2;
	char c;
	char found = 0;
	printf("\nThe Player's Assist is greater than: ");
	scanf("%f",&KEY1);

	printf("\nThe Player's Assist is less than: ");
	scanf("%f",&KEY2);
	
	for(c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++)
	{
		if((Player[c].assist >= KEY1) && (Player[c].assist <= KEY2))
		{
			found = 1;
			printPlayerID(c);
		}
	}
	if(found)
	{
		return;
	}
	printf("There are no players with assist in this range");
}

void printPlayerID(char key)
{
	//printf("\nreturned id :%d",key);
	if( (key >= 0 ) && (key <= PLAYERS_ARRAY_SIZE) )
	{
		if(Player[key].ID != -1)
		{
			printf(" Name: %s \n Weight: %d \n Height: %f \n Defense: %f % \n Number Of Goals: %d \n Speed: %f \n Assists: %f \n Rank: %f \n Club: %s\n", Player[key].name , Player[key].weight , Player[key].height , Player[key].defense , Player[key].num_Goals , Player[key].speed , Player[key].assist , Player[key].rank ,Club[Player[key].club_ID].name);
		}
		else
		{
			printf("No Such a Player/n");
		}
	}
	else
	{
		printf("Wrong Entry/n");
	}
}

void searchForClubMenu()
{
	while(1)
	{
		char Entry;
		char id = 0;
		system("cls");
		printf("                Filters Menu\n");
		printf("                ~~~~~~~~~~~~\n");
		printf("\n\n\t[1]  Search by Name ");
		printf("\n\n\t[2]  Search by Rank ");
		printf("\n\n\t[3]  Return to the Main Menu");
		printf("\n\n\n\t\tEnter your choice --> ");
		Entry = getch();
		switch (Entry)
		{
			case '1':
					id=searchClubName();
					printClubID(id);
					system("pause");
					break;
			case '2':
					id=searchClubRank();
					printClubID(id);
					system("pause");
					break;
			case '3':
					return;
					
			
			default:
					printf( "\nInvalid Choice...");
				
		}
	}
}

void printClubID(char key)
{
	
	char i,temp;
	if(key >= 0 && key <CLUBS_ARRAY_SIZE)
	{
		if(Club[key].ID != -1)
		{
			printf(" Name: %s \n Number Of Goals: %d \n Rank: %d\n" , Club[key].name , Club[key].num_Goals , Club[key].rank);
			printf(" ~~~~~~~~ Team Members ~~~~~~~~\n\n");
			for( i = 0 ; i < CLUB_PLAYERS ; i++)
			{
				temp = Club[key]. players_ID[i];
				if(temp != -1)
				{
					printf(" %d - %s \n", i+1 , Player[temp].name);
				}
			}		
		}
		else
		{
			printf("No Such a Club/n");
		}
	}
	else
	{
		printf("Wrong Entry/n");
	}
}

int searchClubName()
{
	char KEY[NAME_SIZE];
	char c,i;
	char found = 0;
	printf("Enter The Club's Name: ");
	scanf("%s",&KEY);
	for(c = 0 ; c < CLUBS_ARRAY_SIZE ; c++)
	{
		while(KEY[i] != '\0')
		{
			
			if(Club[c].name[i] == KEY[i])
			{
				found++;
				//printf("%d",found);
			}
			c++;
		}
		if(found == i)
		{
			return c;
		}
		
	}
	
	return -1;
}

int searchClubRank()
{
	int KEY;
	char c;
	char found = 0;
	printf("Enter The Club's Rank: ");
	scanf("%d",&KEY);
	for(c = 0 ; c < CLUBS_ARRAY_SIZE ; c++)
	{
		if(Club[c].rank == KEY)
		{
			found = 1;
			break;
		}
	}
	if(found)
	{
		return c;
	}
	return -1;
}
