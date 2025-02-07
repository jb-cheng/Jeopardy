#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

//Global variables
question questions[NUM_QUESTIONS];  // Define globally in only one place


// Initializes the array of questions for the game
void initialize_questions(void)
{
    // initialize each question struct and assign it to the questions array

    // Example initialization
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What primative variable type supports the binary values of 'true' and 'false' ?");
    strcpy(questions[0].answer, "main");
    questions[0].value = 100;
    questions[0].answered = false;
    
    // Repeat for all 12 questions...
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}
