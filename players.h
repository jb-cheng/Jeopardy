/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_LEN 256
#define MAX_SELECTIONS 2 // Maximum times a player can be chosen in a round

// Player struct for each player
typedef struct
{
    char name[MAX_LEN];
    int score;
} player;

// Returns true if the player name matches one of the existing players
extern bool player_exists(player *players, int num_players, char *name);

// Adds a new player with initial score (earnings) of 0
extern void create_new_player(player *players, int *num_players, char *name);

// Updates the score for the player given their name
extern void update_score(player *players, int num_players, char *name, int score);

extern player *select_random_player(player *players, int num_players, int *selection_count);

#endif /* PLAYERS_H_ */
