/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 * Group Members:
 * Anuj Shukla (100895219)
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4


// ANSI escape codes for colors
#define RESET_COLOR "\033[0m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"

//Function declarations
// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);

// Function to get player names and initialize players
void get_player_names(player *players, int *num_players);

// Function to initialize the game and introduce how it works 
void initialize_game();


//Function implementations
int main(int argc, char *argv[])
{
    // An array of 4 players
    player players[NUM_PLAYERS];
    
    // Input buffer and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names and initialize the player array
    int num_players = 0;
    get_player_names(players, &num_players);

    // Display the players and their scores
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %s, Score: %d\n", i + 1, players[i].name, players[i].score);
    }

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files

        // Execute the game until all questions are answered

        // Display the final results and exit
        show_results(players, num_players);
    }
    return EXIT_SUCCESS;
}

// Function to initialize the game and introduce how it works 
void initialize_game()
{
    printf(YELLOW "==============================\n");
    printf("  WELCOME TO JEOPARDY!  \n");
    printf("==============================\n\n");

    // ASCII art for Jeopardy 
    printf(BLUE);
    printf("       #####    ##########   #########   ##########      ######      ##########    ##########   #####   ####  ####\n");
    printf("       #####  ############  ###########  ###########    ########     ###########   ###########  #####  #####  ####\n");
    printf("       #####  ############  ###########  ###########   ##########    ###########   ###########  #####  #####  ####\n");
    printf("       #####  ############  ###########  ###########   ##########    ###########   ###########  #####  #####  ####\n");
    printf("       #####  ############  ###########  ###########   ##########    ###########   ###########  #####  #####  ####\n");
    printf("       #####  ############  ###########  ###########   ##########    ###########   ###########  #####  #####  ####\n");
    printf("       #####  ############  ###########  ###########  ###########    ###########   ###########  #####  #####  ####\n");
    printf("       #####  #####         #####  ####  ####  #####  ###########    #####  ####   #####  ####  #####  #####  ####\n");
    printf("       #####  #####         #####  ####  ####  #####  #####  #####   #####  ####   #####  ####  #####  #####  ####\n");
    printf("#####  #####  ############  #####  ####  ###########  ############   ###########   #####  ####  ############  ####\n");
    printf("#####  #####  ############  #####  ####  ###########  ############   ##########    #####  ####  ############  ####\n");
    printf("#####  #####  #####         #####  ####  #####        #####  #####   ##### #####   #####  ####         #####  ####\n");
    printf("#####  #####  #####         #####  ####  ####         #####  #####   #####  #####  #####  ####         #####  ####\n");
    printf("#####  #####  ######        ###########  ####         ####    ####   #####  #####  #####  ####         #####  ####\n");
    printf("############  ############  ###########  ####         ####    ####   #####  #####  ###########     #########      \n");
    printf(" ##########     #########    #########   ####         ####    ####   #####   #####  #########        #######   ## \n\n");


    // Game instructions/introduction
    printf(CYAN "Ready to test your knowledge? Players will compete in answering questions across various categories.\n");
    printf("Each correct answer earns points, and the player with the highest score wins!\n\n");
    printf(YELLOW "Good luck, and may the best contestant win!\n\n");
    
    printf(RESET_COLOR); // Reset to default color
}

// Displays the game results for each player, their name, and final score, ranked from first to last place
void show_results(player *players, int num_players)
{
    // Sort players in descending order based on score (Bubble Sort for small arrays)
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = 0; j < num_players - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                // Swap players[j] and players[j+1]
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // Print sorted results
    printf("\n===== Final Results =====\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s - %d points\n", i + 1, players[i].name, players[i].score);
    }
}

// Function to prompt users for player names and store them
void get_player_names(player *players, int *num_players)
{
    char name[MAX_LEN];

    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Please provide player %d name: ", i + 1);
        fgets(name, MAX_LEN, stdin);
        
        // Remove trailing newline character
        name[strcspn(name, "\n")] = '\0';

        if (!player_exists(players, *num_players, name))
        {
            create_new_player(players, num_players, name);
        }
        else
        {
            printf("This player already exists. Try a different name.\n");
            i--; // Retry the input for the same player
        }
    }
}

