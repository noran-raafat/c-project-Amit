#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "config.h"

// *******  GLOBAL STRUCTURE for Players *********/
struct Players
{
	signed char ID;
	char name[NAME_SIZE];
	
	float weight;
	float height;
	
	float speed;
	unsigned int num_Goals;
	
	float defense;
	float assist;
	
	signed char club_ID;
	float rank;
};

// ******* GLOBAL STRUCTURE for Clubs ******* /
struct Clubs
{
	signed char ID;
	char name[NAME_SIZE];
	float rank;
	
	signed char players_ID[CLUB_PLAYERS];
	
	unsigned int num_Goals;
	float avg_speed;
	float avg_assist;
	float avg_defense;
};

struct Players Player[PLAYERS_ARRAY_SIZE];
struct Clubs Club[CLUBS_ARRAY_SIZE];

/*******  FUNCTIONS PROTOTYPES  *******/
void addDeleteMenu();
void displayMenu();
void addPlayer();
void displayAllPlayer();
char addClub();
void displayAllClub();
void searchForPlayerMenu();
void printPlayerID(char);
int searchPlayerName();
int searchPlayerRank();
void searchPlayerDeffence();
void searchForClubMenu();
void printClubID(char);
int searchClubName();
int searchClubRank();
void deletePlayer();
void deleteClub();
void displayStats();
char calcStats();
void chooseClub(char );
void searchPlayerSpeed();
void searchPlayerAssist();
void searchPlayerNumGoals();
void searchPlayerWeight();
void searchPlayerHeight();
void searchPlayerDefense();
char validateName(char * );

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

char validateName( char * chPtr)
{
	
	char flag = 0;
	char i;
	char count = 1;
	for (i = 0 ; i < NAME_SIZE  ; i++)
	{
		if (*(chPtr+i) != 0)
		{
			count ++;
	
		}
		else if (*(chPtr+i) == 0)
		{
			flag =1;
			break;
		}
	}
	if (( i == NAME_SIZE) && (flag == 0))
	{
		return 0;
	}
	if ( (count < MIN_NAME) && (count > NAME_SIZE))
	{
		return 0;
	}
	
	for ( i = 0 ; i < NAME_SIZE ; i++)
	{
		if (!( (( *(chPtr+i) >= 65) && (*(chPtr+i) <= 90)) || ((*(chPtr+i) >= 97) && (*(chPtr+i) <= 122))))
		{
		
			return 0;
		}
		else 
		{
			
		}
	}
	return 1;
}

void addDeleteMenu()
{
	while(1)
	{
		char Entry;
		system("cls");
		printf("           Add & Delete Menu\n");
		printf("           ~~~~~~~~~~~~~~~~~\n");
		printf("\n\n\t[1]  Add a Player");
		printf("\n\n\t[2]  Add a Club ");
		printf("\n\n\t[3]  Delete a Player");
		printf("\n\n\t[4]  Delete a Club");
		printf("\n\n\t[5]  Return to the Main Menu");
		printf("\n\n\n\t\tEnter your choice --> ");
		Entry = getch();
		switch (Entry)
		{
			case '1':
					
					addPlayer();
				
					break;
			case '2':
					addClub(Club);
					break;
			case '3':
					deletePlayer();
					break;
			case '4':
					deleteClub();
					break;
			case '5':
					return;
			default:
					printf( "\nInvalid Choice...");
		}
	}
		
}

void addPlayer()
{
	system("cls");
	char c,v;
	for (c = 0; c < PLAYERS_ARRAY_SIZE; c++)
	{
		if (Player[c].ID == -1) //Looking for an empty space in the array
		{
			break;
		}
		
	}
	if ( c == PLAYERS_ARRAY_SIZE )
	{
		printf(" YOU ENTERED THE MAXIMUM NUMBER OF PLAYERS");
	}
	else
	{
		Player[c].ID = c ;
		printf("\n\n\n\n\n\t\t PLAYER DATA\n\n");
		printf(" ENTER THE NAME OF THE PLAYER: ");
		
		scanf("%s", Player[c].name);
		
		v = validateName(Player[c].name);
		
		while (!v)
		{
			printf("\nNOT VALID\n");
			scanf("%s", Player[c].name);

		}
		
		
		printf(" ENTER THE PLAYER'S WEIGHT[kg]: ");
		scanf("%f", &Player[c].weight);
		
		while ( (Player[c].weight < MIN_WEIGHT) && (Player[c].weight < MAX_WEIGHT) )
		{
			printf("\nNOT VALID, WEIGHT MUST BE MORE THAN %d AND LESS THAN %d \n",MIN_WEIGHT,MAX_WEIGHT);
		}
		
		printf(" ENTER THE PLAYER'S HEIGHT[m]: ");
		scanf("%f", &Player[c].height);
		
		while ( (Player[c].height < MIN_HEIGHT) && (Player[c].height < MAX_HEIGHT) )
		{
			printf("\nNOT VALID, HEIGHT MUST BE MORE THAN %d AND LESS THAN %d \n",MIN_HEIGHT,MAX_HEIGHT);
		}
		
		printf(" ENTER THE NUMBER OF GOALS: ");
		scanf("%d", &Player[c].num_Goals);
		
		while ( (Player[c].num_Goals < MIN_GOALS) && (Player[c].num_Goals < MAX_GOALS) )
		{
			printf("\nNOT VALID\n");
		}
		
		printf(" ENTER THE PLAYER's DEFENSE[minutes]: ");
		scanf("%f", &Player[c].defense);
		
		while ( (Player[c].defense < MIN_DEFENSE) && (Player[c].defense < MAX_DEFENSE) )
		{
			printf("\nNOT VALID\n");
		}
		
		printf(" ENTER THE PLAYER'S SPEED[km/hr]: ");
		scanf("%f", &Player[c].speed);
		
		while ( (Player[c].speed < MIN_SPEED) && (Player[c].speed < MAX_SPEED) )
		{
			printf("\nNOT VALID\n");
		}
		
		printf(" ENTER THE PLAYER'S ASSIST: ");
		scanf("%f", &Player[c].assist);
		
		while ( (Player[c].assist < MIN_ASSIST) && (Player[c].assist < MAX_ASSIST) )
		{
			printf("\nNOT VALID\n");
		}
		
		printf(" CHOOSE THE PLAYER'S CLUB: ");
		chooseClub(c);
		
		Player[c].rank = (float)Player[c].num_Goals + Player[c].defense + Player[c].speed + Player[c].assist;
	}
} // end of Add function

char addClub()
{
	char c,v;
	for (c = 0; c < CLUBS_ARRAY_SIZE; c++)
	{
		if (Club[c].ID == -1) //Looking for an empty space in the array
		{
			break;
		}
	}
	
	if ( c == CLUBS_ARRAY_SIZE )
	{
		printf(" YOU ENTERED THE MAXIMUM NUMBER OF CLUBS");
	}
	else
	{
		Club[c].ID = c ;
		printf("\n\n\n\n\n\t\t CLUB DATA\n\n");
		printf(" Enter THE NAME OF THE CLUB: ");
		scanf("%s", Club[c].name);
		v = validateName(Player[c].name);
		
		while (!v)
		{
			printf("\nNOT VALID\n");
			scanf("%s", Club[c].name);

		}
		
	}	
	
	return Club[c].ID;
} // end of Add function



void chooseClub(char p)
{
	int c;
	int Entry;
	char pp;
	char new_ID;
	char num = 0;
	
	for (c = 0; c < CLUBS_ARRAY_SIZE ; c++)
	{
		if (Club[c].ID != -1)
		{
			num++;
			printf("\n\n\t[%d]  %s",num,Club[c].name);
		}
		else if (Club[c].ID == -1)
		{
			break;
		}
		
	}
	printf("\n\n\t[%d]  ENTER NEW CLUB",num+1);
	
	printf("\n\n\n\t\tEnter your choice --> ");
	scanf("%d",&Entry);
	
	if (Entry <= num)
	{
		
		Player[p].club_ID = Club[Entry-1].ID; //put club ID in club_ID in player struct
		for ( pp = 0 ; p < CLUB_PLAYERS ; p++)
		{
			if (Club[Entry-1].players_ID[pp] == -1)  //Looking for an empty space in the array
			{
				break;
			}
		}
		if ( pp == CLUB_PLAYERS)
		{
			printf("You added the maximum number of players");
		}
		Club[Entry-1].players_ID[pp] = Player[p].ID;
	}
	else if (Entry > num )
	{
		
		new_ID = addClub();
		Player[p].club_ID = Club[new_ID].ID;
		Club[new_ID].players_ID[0] = Player[p].ID;
	}
	else
	{
		printf("INVALID CHOICE ");
	}
}

/*
void addPlayer2Club(char c, )
{
	for ( i = 0; i < CLUB_PLAYERS ; i++)
	{
		if(Club[c].players_ID[i] != -1)
		{
			Club[c].players_ID[i] = 
		}
	
}

*/

void deleteClub()
{
	char key,i,temp, ch;
	char j, m, n;
	char ACK = 'K';
	printf("\n\n\tChoose a Club to delete: ");
	
	for ( j = 0 ; j < CLUBS_ARRAY_SIZE ; j++)
	{
		if (Club[j].ID != -1)
		{
			printf("\n\n\t[%d]  %s",j+1,Club[j].name);
		}
	}
	
	printf("\n\n\n\t\tEnter your choice --> ");
	scanf("%d",&key);
	key--;
	if( (key >= 0) && (key < CLUBS_ARRAY_SIZE) )
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
			printf("ARE YOU SURE, you want to delete the club and the players ? \n Press y to delete, n to cancel");
			while (1)
			{
				ACK=getch();
				if (ACK == 'y' || ACK =='n' || ACK == 'Y' || ACK =='N')
				{
					break;
				}
			}
			if(ACK == 'y'|| ACK=='Y')
			{
				for( i = 0 ; i < CLUB_PLAYERS ; i++)
				{
					temp = Club[key]. players_ID[i];
					if(temp != -1)
					{
						Player[temp].ID = -1;
						
						 for ( n = temp+1 ; n < PLAYERS_ARRAY_SIZE ; n++ ) 
						 {
							 Player[n-1].ID = Player[n].ID;
							 for ( ch = 0 ; ch < NAME_SIZE ; ch++)
							 {
								 Player[n-1].name[ch] = Player[n].name[ch] ;
							 }
							printf("%s",Player[n-1].name);
							system("pause");
							 Player[n-1].height = Player[n].height;
							 Player[n-1].weight = Player[n].weight;
							 Player[n-1].speed = Player[n].speed;
							 Player[n-1].assist = Player[n].assist;
							 Player[n-1].defense = Player[n].defense;
							 Player[n-1].num_Goals = Player[n].num_Goals;
							 Player[n-1].club_ID = Player[n].club_ID;
							 Player[n-1].rank = Player[n].rank;
						 }
					}
				}
				Club[key].ID = -1;
				for ( m = key+1 ; m < CLUBS_ARRAY_SIZE ; m++ ) 
				{
					Club[m-1].ID = Club[m].ID;
					*(Club[m-1].name) = *(Club[m].name) ;
					printf("%s",Club[m-1].name);
					system("pause");
					Club[m-1].avg_speed = Club[m].avg_speed;
					Club[m-1].avg_assist = Club[m].avg_assist;
					Club[m-1].avg_defense = Club[m].avg_defense;
					Club[m-1].num_Goals = Club[m].num_Goals;
					Club[m-1].rank = Club[m].rank;
							 
				}
				return;
			}
			return;
		}
		else
		{
			printf("No Such Club/n");
		}
	}
	else
	{
		printf("Wrong Entry/n");
	}
	
}

void deletePlayer()
{
	char n,j;
	char key;
	char ACK = 'K';
	printf("\n\n\tChoose a Player to delete: ");
	
	for ( j = 0 ; j < PLAYERS_ARRAY_SIZE ; j++)
	{
		if (Player[j].ID != -1)
		{
			printf("\n\n\t[%d]  %s",j+1,Player[j].name);
		}
	}
	
	printf("\n\n\n\t\tEnter your choice --> ");
	scanf("%d",&key);
	key--;
	if(key >= 0 && key < PLAYERS_ARRAY_SIZE)
	{
		if(Player[key].ID != -1)
		{
			printf(" Name: %s \n Weight: %f.2 \n Height: %f.2 \n Defense: %f % \n Number Of Goals: %d \n Speed: %d \n Assists: %d \n Rank: %d \n Club: %s\n", Player[key].name , Player[key].weight , Player[key].height , Player[key].defense , Player[key].num_Goals , Player[key].speed,Player[key].assist,Player[key].rank ,Club[Player[key].club_ID].name);
			printf("ARE YOU SURE ? \n Press y to delete, n to cancel");
			while (1)
			{
				ACK=getch();
				if (ACK == 'y' || ACK =='n' || ACK == 'Y' || ACK =='N')
				{
					break;
				}
			}
			if(ACK == 'y'|| ACK=='Y')
			{
				Player[key].ID = -1;
				for ( n = key+1 ; n < PLAYERS_ARRAY_SIZE ; n++ ) 
				 {
					 Player[n-1].ID = Player[n].ID;
					 *(Player[n-1].name) = *(Player[n].name) ;
					 printf("%s",Player[n-1].name);
					 system("pause");
					 Player[n-1].height = Player[n].height;
					 Player[n-1].weight = Player[n].weight;
					 Player[n-1].speed = Player[n].speed;
					 Player[n-1].assist = Player[n].assist;
					 Player[n-1].defense = Player[n].defense;
					 Player[n-1].num_Goals = Player[n].num_Goals;
					 Player[n-1].club_ID = Player[n].club_ID;
					 Player[n-1].rank = Player[n].rank;
				 }
				return;
			}
			return;
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
			printf(" Name: %s \n Weight: %f.2 \n Height: %f.2 \n Defense: %f % \n Number Of Goals: %d \n Speed: %d \n Assists: %d \n Rank: %d \n Club: %s\n", Player[c].name , Player[c].weight , Player[c].height , Player[c].defense , Player[c].num_Goals , Player[c].speed , Player[c].assist , Player[c].rank ,Club[Player[c].club_ID].name);
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
			printf(" Name: %s \n Number Of Goals: %d \n Rank: %d\n" , Club[c].name , Club[c].num_Goals , Club[c].rank);
			printf(" ~~~~~~~~ Team Members ~~~~~~~~\n\n");
			for( i = 0 ; i < CLUB_PLAYERS ; i++)
			{
				g = Club[c]. players_ID[i];
				printf("Players ID = %d",Club[c].players_ID[i]);
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
		printf("There are %d Clubs\n" ,x );
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
					printPlayerID(id);
					system("pause");
					break;
			case '4':
					searchPlayerWeight();
					printPlayerID(id);
					system("pause");
					break;
			case '5':
					searchPlayerNumGoals();
					printPlayerID(id);
					system("pause");
					break;
			case '6':
					searchPlayerDefense();
					printPlayerID(id);
					system("pause");
					break;
			case '7':
					searchPlayerSpeed();
					printPlayerID(id);
					system("pause");
					break;
					return;
			case '8':
					searchPlayerAssist();
					printPlayerID(id);
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
	char KEY[20];
	char c;
	char found = 0;
	printf("Enter The Player's Name: ");
	scanf("%s",&KEY);
	for(c = 0 ; c < PLAYERS_ARRAY_SIZE ; c++)
	{
		if(Player[c].name == KEY)
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
	printf("The Player's Defencse is greater than: ");
	scanf("%f",&KEY1);
	printf("The Player's Defence is less than: ");

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
	printf("The Player's Height is greater than: ");
	scanf("%f",&KEY1);
	printf("The Player's Height is less than: ");

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
	printf("There are no players with height in this range");
}

void searchPlayerWeight()
{
	float KEY1,KEY2;
	char c;
	char found = 0;
	printf("The Player's Weight is greater than: ");
	scanf("%f",&KEY1);
	printf("The Player's Weight is less than: ");

	scanf("%f",&KEY2);
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
	printf("The Player's Speed is greater than: ");
	scanf("%f",&KEY1);
	printf("The Player's Speed is less than: ");

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
	printf("The Player's Number of Goals is greater than: ");
	scanf("%f",&KEY1);
	printf("The Player's Number of Goals is less than: ");

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
	printf("The Player's Assist is greater than: ");
	scanf("%f",&KEY1);

	printf("The Player's Assist is less than: ");
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
	
	if(key >= 0 && key < PLAYERS_ARRAY_SIZE)
	{
		if(Player[key].ID != -1)
		{
			printf(" Name: %s \n Weight: %f.2 \n Height: %f.2 \n Defense: %f % \n Number Of Goals: %d \n Speed: %d \n Assists: %d \n Rank: %d \n Club: %s\n", Player[key].name , Player[key].weight , Player[key].height , Player[key].defense , Player[key].num_Goals , Player[key].speed , Player[key].assist , Player[key].rank ,Club[Player[key].club_ID].name);
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
	char c;
	char found = 0;
	printf("Enter The Club's Name: ");
	scanf("%s",&KEY);
	for(c = 0 ; c < CLUBS_ARRAY_SIZE ; c++)
	{
		if(Club[c].name == KEY)
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


char calcStats()
{
	char c , p , tmp_ID;
	int found_player = 0;
	char found_club = 0;

	float avg_speed, avg_defense , avg_assist;
	float sum_speed, sum_defense , sum_assist , sum_numGoals;

	for ( c = 0 ; c < CLUBS_ARRAY_SIZE ; c++)
	{
		if (Club[c].ID != -1)
		{
			found_club ++;
			sum_speed  = 0;
			sum_defense = 0;
			sum_assist = 0;
			sum_numGoals = 0;
			
			for ( p = 0 ; p < PLAYERS_ARRAY_SIZE ; p++)
			{
				if (Club[c].players_ID[p] != -1)
				{
					found_player ++;
					tmp_ID = Club[c].players_ID[p];
					
					sum_numGoals = sum_numGoals + Player[tmp_ID].num_Goals;
					sum_speed = sum_speed  + Player[tmp_ID].speed;
					sum_defense = sum_defense  + Player[tmp_ID].defense;
					sum_assist = sum_assist  + Player[tmp_ID].assist;

				}

				
			}
			
			Club[c].num_Goals = sum_numGoals;
			Club[c].avg_speed = sum_speed/found_player;
			Club[c].avg_defense = sum_defense/found_player;
			Club[c].avg_assist = sum_assist/found_player;
			Club[c].rank = Club[c].num_Goals + Club[c].avg_speed + Club[c].avg_defense + Club[c].avg_assist ; 
		} 
			
	}
	return found_club ;
}

void displayStats()
{
	char c, found_club ; 
	system("cls");
	found_club = calcStats();
	
	if (found_club == 0)
	{
		printf("No Clubs to display");
		return ;
	}		
	else
	{
		for ( c = 0 ; c < CLUBS_ARRAY_SIZE ; c++)
		{
			if (Club[c].ID != -1)
			{
				printf(" Name: %s \n Number Of Goals: %d \n Rank: %d \n Average Speed: %f \n Average Defense: %f \n Average Assists: %f \n" , Club[c].name , Club[c].num_Goals , Club[c].rank, Club[c].avg_speed , Club[c].avg_defense , Club[c].avg_assist );
				printf("\n---------------------------\n");
			}
		}		
	}
	system("pause");
}
