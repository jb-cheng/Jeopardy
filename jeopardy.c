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
#include <wchar.h>
#include <locale.h>
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

// Function declarations
//  Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);

// Function to get player names and initialize players
void get_player_names(player *players, int *num_players);

// Function to initialize the game and introduce how it works
void initialize_game();

void play_game(player *players, int num_players);

// Function implementations
int compare_scores(const void* a, const void* b) {
    return ((player*)b)->score - ((player*)a)->score;
}

int main(void)
{
    // An array of 4 players
    player players[NUM_PLAYERS];

    // Display the game introduction and initialize the questions
    initialize_game();
    initialize_questions();

    // Prompt for players' names and initialize the player array
    int num_players = 0;
    get_player_names(players, &num_players);

    // Start the game
    play_game(players, num_players);

    // Display the final results and exit
    // Display the players and their scores
    int n = sizeof(players) / sizeof(players[0]);
    qsort(players, n, sizeof(player), compare_scores);

    setlocale(LC_ALL, ""); // Enable Unicode support
    wchar_t crown = L'👑'; // Unicode crown character
    wprintf(L"%lc ", crown); // Print the emoji
    printf("Player %d: %s, Score: %d\n", 1, players[0].name, players[0].score);
    for (int i = 1; i < num_players; i++)
    {
        printf("   Player %d: %s, Score: %d\n", i + 1, players[i].name, players[i].score);
    }

    printf("CONGRATULATIONS PLAYER %s!\n\n", players[0].name);
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

void tokenize(char *input, char **tokens)
{
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL && i < 3)
    {
        tokens[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
}
// Displays the game results for each player, their name, and final score, ranked from first to last place
void show_results(player *players, int num_players)
{
    // Sort players in descending order based on score (Bubble Sort for small arrays)
    for (int i = 0; i < num_players - 1; i++)
    {
        for (int j = 0; j < num_players - i - 1; j++)
        {
            if (players[j].score < players[j + 1].score)
            {
                // Swap players[j] and players[j+1]
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // Print sorted results
    printf("\n===== Final Results =====\n");
    for (int i = 0; i < num_players; i++)
    {
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

void play_game(player *players, int num_players)
{
    char buffer[BUFFER_LEN];
    int current_player = 0;

    while (1)
    {
        // Display the categories and dollar values
        display_categories();
        do
        {
            // Prompt the current player to select a category and dollar amount
            printf("%s, it's your turn!\n", players[current_player].name);
            printf("Enter the category and dollar amount (e.g., 'History 200'): ");
            fgets(buffer, BUFFER_LEN, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
        } while (strlen(buffer) == 0);
        // Parse the category and dollar amount
        char category[MAX_LEN];
        int value;
        sscanf(buffer, "%s %d", category, &value);

        // Validate the category and dollar amount
        if (already_answered(category, value))
        {
            printf("This question has already been answered. Please choose another.\n");
            continue;
        }

        // Display the question
        display_question(category, value);

        // Prompt the player for the answer
        do
        {
            printf("Your answer (start with 'what is' or 'who is'): ");
            fgets(buffer, BUFFER_LEN, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
        } while (strlen(buffer) == 0);

        // Tokenize the answer
        char *tokens[3];
        tokenize(buffer, tokens);

        // Validate the answer format
        if (strcasecmp(tokens[0], "what") != 0 && strcasecmp(tokens[0], "who") != 0)
        {
            printf("Invalid answer format. Please start with 'What is' or 'Who is'.\n");
            continue;
        }

        // Check if the answer is correct
        if (valid_answer(category, value, tokens[0], tokens[2]))
        {
            printf("Correct!\n");
            update_score(players, num_players, players[current_player].name, value);
        }
        else
        {
            printf("Incorrect. The correct answer is: %s\n", get_answer(category, value));
        }

        // Mark the question as answered
        mark_answered(category, value);

        // Check if all questions have been answered
        if (all_questions_answered())
        {
            printf("All questions have been answered!\n");
            break;
        }

        // Move to the next player
        current_player = (current_player + 1) % num_players;
    }
}
