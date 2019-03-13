#include "config.h"



// *******  GLOBAL STRUCTURE for Players *********/
typedef struct 
{
	signed char ID;
	char name[NAME_SIZE];
	
	int weight;
	float height;
	
	float speed;
	unsigned int num_Goals;
	
	float defense;
	float assist;
	
	signed char club_ID;
	float rank;
}Players_t;

// ******* GLOBAL STRUCTURE for Clubs ******* /
typedef struct 
{
	signed char ID;
	char name[NAME_SIZE];
	float rank;
	
	signed char players_ID[CLUB_PLAYERS];
	
	unsigned int num_Goals;
	float avg_speed;
	float avg_assist;
	float avg_defense;
}Clubs_t;