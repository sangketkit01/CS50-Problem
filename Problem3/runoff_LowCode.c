//************************ This runoff i've done , i did it without understanding what runoff actually is ***********************
//************************ Cause i didn't watch walkthrough video so i don't know what function is required to have ***********************
//************************ Harvard did make requirement that everyone must follow but i didn't  ***********************
//************************ Anyway i've done this in my own way even it's not it should be but it's work  in it own way ***********************

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

#define MAX 9

bool vote(char *name, int rank);
char *upperString(char *s);
char *removeSpace(const char *s);
bool stringCompare(char *s1, char *s2);
int stringLength(char *s);

typedef struct
{
    char *name;
    int votes;
} Candidates;

Candidates candidate[MAX];

int candidate_count;
char *newString;
char *upper;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 1;
    }

    for (int i = 1; i <= candidate_count; i++)
    {
        candidate[i - 1].name = argv[i];
        candidate[i - 1].votes = 0;
    }

    int voters = get_int("Number of voters: ");
    for (int i = 0; i < voters; i++)
    {
        int rank_score = candidate_count;
        for (int j = 0; j < candidate_count; j++)
        {
            char *rank_vote = get_string("Rank %d: ", j + 1);
            if (vote(rank_vote, rank_score))
            {
                rank_score--;
            }
            else
            {
                printf("Invalid vote.\n");
            }
        }
        printf("\n");
    }

    char *winner = "";
    int maxScore = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidate[i].votes > maxScore)
        {
            maxScore = candidate[i].votes;
            winner = candidate[i].name;
        }
    }
    printf("%s\n", winner);

    return 0;
}

bool vote(char *name, int rank)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (stringCompare(upperString(candidate[i].name), upperString(name)))
        {
            candidate[i].votes += rank;
            return true;
        }
    }
    return false;
}

char *upperString(char *s)
{

    upper = malloc(stringLength(s) + 1); // Upper has Declared on the top of main function

    if (upper == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int index;
    int length = 0;
    for (index = 0; s[index] != '\0'; index++)
    {
        upper[index] = s[index];
        length++;
    }
    upper[index] = '\0';

    for (int i = 0; i < length; i++)
    {
        if (upper[i] <= 90)
        {
            upper[i] = upper[i] + 32;
        }
    }
    return upper;
}

char *removeSpace(const char *s)
{
    int newSize = 0;
    for (int i = 0; i < stringLength(s); i++)
    {
        if (s[i] != ' ')
        {
            newSize++;
        }
    }

    newString = malloc(newSize + 1); // newString has Declared on the top of main function
    if (newString == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            newString[j++] = s[i];
        }
    }
    newString[j] = '\0';

    return newString;
}

bool stringCompare(char *s1, char *s2)
{
    if (stringLength(s1) != stringLength(s2) || s1 == NULL || s2 == NULL)
    {
        return false;
    }

    for (int i = 0; i < stringLength(s1); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}

bool stringCompareIgnoreCase(char *s1, char *s2)
{
    if (stringLength(s1) != stringLength(s2) || s1 == NULL || s2 == NULL)
    {
        return false;
    }

    char *newS1 = upperString(s1), newS2 = upperString(s2);
    for (int i = 0; newS1[i] != '\0' && newS2[i] != '\0'; i++)
    {
        if (newS1[i] != newS2[i])
        {
            return false;
        }
    }
    return true;
}

int stringLength(char *s)
{
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

free(upper);
free(newString);