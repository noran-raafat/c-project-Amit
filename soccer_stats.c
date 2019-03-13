#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "config.h"
#include "soccer_types.h"
#include "soccer.h"

extern Players_t Player[PLAYERS_ARRAY_SIZE];
extern Clubs_t Club[CLUBS_ARRAY_SIZE];

char calcStats()
{
	char c , p , tmp_ID;
	int found_player = 0;
	char found_club = 0;

	float avg_speed, avg_defense , avg_assist;
	float sum_speed, sum_defense , sum_assist ;
	unsigned int sum_numGoals;

	/* Loops on all clubs*/
	for ( c = 0 ; c < CLUBS_ARRAY_SIZE ; c++)
	{
		if (Club[c].ID != -1)  /*  search for clubs*/
		{
			found_club++;
			sum_speed  = (float)0;
			sum_defense = (float)0;
			sum_assist = (float)0;
			sum_numGoals = 0;
			
			for ( p = 0 ; p < CLUB_PLAYERS ; p++)   /* loops on all players */
			{
				if (Club[c].players_ID[p] != -1)       /* if found a player Id for the club */
				{
					found_player++;
					tmp_ID = Club[c].players_ID[p];
					sum_numGoals = sum_numGoals + Player[tmp_ID].num_Goals;  /* add number of goals of that player to the sum of goals*/
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
		if ( (found_player == 0) && (p == CLUB_PLAYERS) )
		{
			Club[c].num_Goals = 0;
			Club[c].avg_speed = 0;
			Club[c].avg_defense = 0;
			Club[c].avg_assist = 0;
			Club[c].rank = 0 ; 
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
				printf(" Name: %s \n Number Of Goals: %d \n Rank: %f \n Average Speed: %f \n Average Defense: %f \n Average Assists: %f \n" , Club[c].name , Club[c].num_Goals , Club[c].rank, Club[c].avg_speed , Club[c].avg_defense , Club[c].avg_assist );
				printf("\n---------------------------\n");
			}
		}		
	}
	system("pause");
}
