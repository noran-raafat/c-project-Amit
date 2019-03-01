#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "config.h"
#include "soccer_types.h"
#include "soccer.h"

extern Players_t Player[PLAYERS_ARRAY_SIZE];
extern Clubs_t Club[CLUBS_ARRAY_SIZE];



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
			printf("\n ENTER THE NAME OF THE PLAYER: ");
			scanf("%s", Player[c].name);

		}
		
		
		printf(" ENTER THE PLAYER'S WEIGHT[kg]: ");
		scanf("%d", &Player[c].weight);
		
		while ( (Player[c].weight < MIN_WEIGHT) || (Player[c].weight > MAX_WEIGHT) )
		{
			printf("%d", Player[c].weight);
			printf("\nNOT VALID, WEIGHT MUST BE MORE THAN %d AND LESS THAN %d \n",MIN_WEIGHT,MAX_WEIGHT);
			printf(" ENTER THE PLAYER'S WEIGHT[kg]: ");
			scanf("%d", &Player[c].weight);
		}
		
		printf(" ENTER THE PLAYER'S HEIGHT[m]: ");
		scanf("%f", &Player[c].height);
		
		while ( (Player[c].height < MIN_HEIGHT) || (Player[c].height > MAX_HEIGHT) )
		{
			printf("\nNOT VALID, HEIGHT MUST BE MORE THAN %d AND LESS THAN %d \n",MIN_HEIGHT,MAX_HEIGHT);
			printf(" ENTER THE PLAYER'S HEIGHT[m]: ");
			scanf("%f", &Player[c].height);
		}
		
		printf(" ENTER THE NUMBER OF GOALS: ");
		scanf("%d", &Player[c].num_Goals);
		
		while ( (Player[c].num_Goals < MIN_GOALS) || (Player[c].num_Goals > MAX_GOALS) )
		{
			printf("\nNOT VALID\n");
			printf(" ENTER THE NUMBER OF GOALS: ");
			printf(" ENTER THE NUMBER OF GOALS: ");
			scanf("%d", &Player[c].num_Goals);
		}
		
		printf(" ENTER THE PLAYER's DEFENSE[minutes]: ");
		scanf("%f", &Player[c].defense);
		
		while ( (Player[c].defense < MIN_DEFENSE) || (Player[c].defense > MAX_DEFENSE) )
		{
			printf("\nNOT VALID\n");
			printf(" ENTER THE PLAYER's DEFENSE[minutes]: ");
			scanf("%f", &Player[c].defense);
		}
		
		printf(" ENTER THE PLAYER'S SPEED[km/hr]: ");
		scanf("%f", &Player[c].speed);
		
		while ( (Player[c].speed < MIN_SPEED) || (Player[c].speed > MAX_SPEED) )
		{
			printf("\nNOT VALID\n");
			printf(" ENTER THE PLAYER'S SPEED[km/hr]: ");
			scanf("%f", &Player[c].speed);
		}
		
		printf(" ENTER THE PLAYER'S ASSIST: ");
		scanf("%f", &Player[c].assist);
		
		while ( (Player[c].assist < MIN_ASSIST) || (Player[c].assist > MAX_ASSIST) )
		{
			printf("\nNOT VALID\n");
			printf(" ENTER THE PLAYER'S ASSIST: ");
			scanf("%f", &Player[c].assist);
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
		printf(" ENTER THE NAME OF THE CLUB: ");
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
		
		for ( pp = 0 ; pp < CLUB_PLAYERS ; pp++)
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
		else if ( pp < CLUB_PLAYERS)
		{
			Club[Entry-1].players_ID[pp] = Player[p].ID;
		}
		
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

void deletePlayer()
{
	int key;
	char ACK = 'K';
	printf("\n\n\tEnter the player's ID: ");
	scanf("%d",&key);
	key--;
	if(key >= 0 && key < players_array_size)
	{
		if(Player[key].ID != -1)
		{
			printf(" Name: %s \n Weight: %d \n Height: %f \n Defense: %f % \n Number Of Goals: %d \n Speed: %f \n Assists: %f \n Rank: %f \n Club: %s\n", Player[c].name , Player[c].weight , Player[c].height , Player[c].defense , Player[c].num_Goals , Player[c].speed , Player[c].assist , Player[c].rank ,Club[Player[c].club_ID].name);
			printf("ARE YOU SHURE ? \n Press y to delete, n to cancel");
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

void deleteClub()
{
	int key,i,temp;
	char ACK = 'K';
	printf("\n\n\tEnter the club's ID: ");
	scanf("%d",&key);
	key--;
	if(key >= 0 && key < clubs_array_size)
	{
		if(Club[key].ID != -1)
		{
			printf(" Name: %s \n Number Of Goals: %d \n Rank: %f\n" , Club[key].name , Club[key].num_Goals , Club[key].rank);
			printf(" ~~~~~~~~ Team Members ~~~~~~~~\n\n");
			for( i = 0 ; i < CLUB_PLAYERS ; i++)
			{
				temp = Club[key]. players_ID[i];
				if(temp != -1)
				{
					printf(" %d - %s \n", i+1 , Player[temp].name);
				}
			}	
			printf("ARE YOU SHURE, you want to delete the club and the players ? \n Press y to delete, n to cancel");
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
						Player[temp].ID=-1;
					}
				}
				Club [key].ID = -1;
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
/*void deleteClub()
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
	
}*/


/*
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
			printf(" Name: %s \n Weight: %d \n Height: %f \n Defense: %f % \n Number Of Goals: %d \n Speed: %f \n Assists: %f \n Rank: %f \n Club: %s\n", Player[key].name , Player[key].weight , Player[key].height , Player[key].defense , Player[key].num_Goals , Player[key].speed,Player[key].assist,Player[key].rank ,Club[Player[key].club_ID].name);
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

char validateName( char * chPtr)
{
	
	char flag = 0;
	char i;
	char count = 0;
	
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
	
	for ( i = 0 ; i < count ; i++)
	{
		
		if ( !( ( ( *(chPtr+i) >= 65 ) && ( *(chPtr+i) <= 90 ) ) || ( ( *(chPtr+i) >= 97 ) && ( *(chPtr+i) <= 122 ) ) ) )
		{
			
			return 0;
		}
		else 
		{
			
		}
	}
	return 1;
}*/

