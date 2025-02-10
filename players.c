/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "players.h"

#define MAX_SELECTIONS 2 // Maximum times a player can be chosen in a round

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{
    for (int i = 0; i < num_players; i++)
    {
        if (strcmp(players[i].name, name) == 0)
        {
            return true;
        }
    }
    return false;
}

// Adds a new player to the game with an initial score of 0
void create_new_player(player *players, int *num_players, char *name)
{
    if (*num_players < 4) // Ensuring we don't exceed max players
    {
        strcpy(players[*num_players].name, name);
        players[*num_players].score = 0;
        (*num_players)++; // Increase the count of players
    }
    else
    {
        printf("Maximum number of players reached!\n");
    }
}

// Go through the list of players and update the score for the given name
void update_score(player *players, int num_players, char *name, int score)
{
    for (int i = 0; i < num_players; i++)
    {
        if (strcmp(players[i].name, name) == 0)
        {
            players[i].score += score;
            return;
        }
    }
    printf("Player not found!\n");
}

// Function to randomly select a player while ensuring no player is chosen more than 3 times
player *select_random_player(player *players, int num_players, int *selection_count)
{
    int available_players = 0;
    int valid_indices[num_players];

    // Identify players who have been chosen less than MAX_SELECTIONS times
    for (int i = 0; i < num_players; i++)
    {
        if (selection_count[i] < MAX_SELECTIONS)
        {
            valid_indices[available_players] = i;
            available_players++;
        }
    }

    // If no players are available, return NULL
    if (available_players == 0)
    {
        printf("All players have been chosen 3 times!\n");
        return NULL;
    }

    // Randomly select from available players
    int random_index = rand() % available_players;
    int chosen_index = valid_indices[random_index];

    // Update selection count
    selection_count[chosen_index]++;

    return &players[chosen_index];
}
