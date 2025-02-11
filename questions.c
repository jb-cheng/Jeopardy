#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Global variables
question questions[NUM_QUESTIONS]; // Define globally in only one place
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
// Initializes the array of questions for the game
void initialize_questions(void)
{
    // initialize each question struct and assign it to the questions array

    // Example initialization what
    strcpy(questions[0].category, "Programming");
    strcpy(questions[0].question, "What primative variable type supports the binary values of 'true' and 'false'? (Enter Full Form)");
    strcpy(questions[0].answer, "boolean");
    strcpy(questions[0].type, "what");
    questions[0].value = 100;
    questions[0].answered = false;

    // Repeat for all 16 questions... //what
    strcpy(questions[1].category, "Programming");
    strcpy(questions[1].question, "Which language is primarily used for Android app development?");
    strcpy(questions[1].answer, "Java");
    strcpy(questions[1].type, "what");
    questions[1].value = 200;
    questions[1].answered = false;

    // what
    strcpy(questions[2].category, "Programming");
    strcpy(questions[2].question, "What does HTML stand for?");
    strcpy(questions[2].answer, "Hypertext Markup Language");
    strcpy(questions[2].type, "what");
    questions[2].value = 300;
    questions[2].answered = false;

    // what
    strcpy(questions[3].category, "Programming");
    strcpy(questions[3].question, "Which language is widely used for machine learning?");
    strcpy(questions[3].answer, "Python");
    strcpy(questions[3].type, "what");
    questions[3].value = 400;
    questions[3].answered = false;

    // Math category
    // what
    strcpy(questions[4].category, "Math");
    strcpy(questions[4].question, "What is the value of pi up to two decimal places?");
    strcpy(questions[4].answer, "3.14");
    strcpy(questions[4].type, "what");
    questions[4].value = 100;
    questions[4].answered = false;

    // what
    strcpy(questions[5].category, "Math");
    strcpy(questions[5].question, "What is the square root of 16?");
    strcpy(questions[5].answer, "4");
    strcpy(questions[5].type, "what");
    questions[5].value = 200;
    questions[5].answered = false;

    // what
    strcpy(questions[6].category, "Math");
    strcpy(questions[6].question, "What is 7 times 8?");
    strcpy(questions[6].answer, "56");
    strcpy(questions[6].type, "what");
    questions[6].value = 300;
    questions[6].answered = false;

    // what
    strcpy(questions[7].category, "Math");
    strcpy(questions[7].question, "What is the derivative of x^2? ");
    strcpy(questions[7].answer, "2x");
    strcpy(questions[7].type, "what");
    questions[7].value = 400;
    questions[7].answered = false;

    // Geography category
    // what
    strcpy(questions[8].category, "Geography");
    strcpy(questions[8].question, "What is the capital of France?");
    strcpy(questions[8].answer, "Paris");
    strcpy(questions[8].type, "what");
    questions[8].value = 100;
    questions[8].answered = false;

    // what
    strcpy(questions[9].category, "Geography");
    strcpy(questions[9].question, "Which country is known as the 'Land of the Rising Sun'?");
    strcpy(questions[9].answer, "Japan");
    strcpy(questions[9].type, "what");
    questions[9].value = 200;
    questions[9].answered = false;

    // what
    strcpy(questions[10].category, "Geography");
    strcpy(questions[10].question, "Which continent is the largest by area?");
    strcpy(questions[10].answer, "Asia");
    strcpy(questions[10].type, "what");
    questions[10].value = 300;
    questions[10].answered = false;

    // what
    strcpy(questions[11].category, "Geography");
    strcpy(questions[11].question, "What river is the longest in the world?");
    strcpy(questions[11].answer, "Nile");
    strcpy(questions[11].type, "what");
    questions[11].value = 400;
    questions[11].answered = false;

    // History category
    // who
    strcpy(questions[12].category, "History");
    strcpy(questions[12].question, "Who was the first President of the United States?(Last Name)");
    strcpy(questions[12].answer, "Washington");
    strcpy(questions[12].type, "who");
    questions[12].value = 100;
    questions[12].answered = false;

    // what
    strcpy(questions[13].category, "History");
    strcpy(questions[13].question, "In what year did World War II end?");
    strcpy(questions[13].answer, "1945");
    strcpy(questions[13].type, "what");
    questions[13].value = 200;
    questions[13].answered = false;

    // who
    strcpy(questions[14].category, "History");
    strcpy(questions[14].question, "Who was the first man to step on the moon?(First Name)");
    strcpy(questions[14].answer, "Neil");
    strcpy(questions[14].type, "who");
    questions[14].value = 300;
    questions[14].answered = false;

    // what
    strcpy(questions[15].category, "History");
    strcpy(questions[15].question, "What modern-day country houses the ancient Great Pyramid of Giza?");
    strcpy(questions[15].answer, "Egypt");
    strcpy(questions[15].type, "what");
    questions[15].value = 400;
    questions[15].answered = false;
}
static char categories[NUM_CATEGORIES][MAX_LEN] = {
    "Programming",
    "Math",
    "Geography",
    "History",

};

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("\n");
    printf("-------------------------------------------------------------\n");

    // Print category headers
    for (int i = 0; i < NUM_CATEGORIES; i++)
    {
        printf("| %-12s ", categories[i]);
    }
    printf("|\n-------------------------------------------------------------\n");

    // Print dollar values for each category
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < NUM_CATEGORIES; row++)
        {
            int index = row * NUM_CATEGORIES + col;
            if (!questions[index].answered)
                printf("| %-12d ", questions[index].value);
            else
                printf("| %-12s ", "            "); // Mark answered questions
        }
        printf("|\n");
    }
    printf("-------------------------------------------------------------\n");
    printf("\n");
}

// Displays the question for the category and dollar value
bool display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            printf("Question: %s\n", questions[i].question);
            return true;
        }
    }
    printf("Invalid category or value, please try again.\n");
    return false;
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer, char *type)
{
    // Look into string comparison functions
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            if (strcasecmp(questions[i].type, type) != 0)
            {
                return false; // Answer format does not match
            }
            return strcasecmp(questions[i].answer, answer) == 0;
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            return questions[i].answered;
        }
    }
    return false;
}

void mark_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            questions[i].answered = true;
            return;
        }
    }
}

// Returns true if all questions have been answered
bool all_questions_answered(void)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (!questions[i].answered)
        {
            return false;
        }
    }
    return true;
}

// Returns the correct answer for a given category and dollar value
char *get_answer(char* string, char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            return questions[i].answer;
        }
    }
    return "Invalid category or value.";
}