//************************ This runoff i've done , i did it without understanding what runoff actually is ***********************
//************************ Cause i didn't watch walkthrough video so i don't know what function is required to have ***********************
//************************ Harvard did make requirement that everyone must follow but i didn't  ***********************
//************************ Anyway i've done this in my own way even it's not it should be but it's work  in it own way ***********************

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

bool checkCandidate(string vote, int argc, char *argv[]);
int voteCandidate(char **candidate, char *vote, int numberOfCandidate);
char *upperString(char *s);
void capitalize(char *s);
char *removeSpace(char *s);
bool stringCompare(char *s1, char *s2);
int stringLength(char *s);

char *newString;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    int *score = malloc((argc - 1) * sizeof(int));
    char **candidates = malloc((argc - 1) * sizeof(string));

    for (int i = 1; i < argc; i++)
    {
        candidates[i - 1] = argv[i];
        score[i - 1] = 0;
    }

    int votes = get_int("Number of voters: ");
    for (int i = 0; i < votes; i++)
    {
        int rankScore = argc - 1;
        for (int j = 0; j < argc - 1; j++)
        {
            int count = j + 1;
            string rank = get_string("Rank %d: ", count);
            if (!checkCandidate(rank, argc, argv))
            {
                printf("Invalid vote.");
                return 1;
            }
            else
            {
                score[voteCandidate(candidates, rank, argc - 1)] += rankScore;
                rankScore--;
            }
        }
        printf("\n");
    }

    int maxValue = 0;
    int maxIndex = 0;
    for (int i = 1; i < argc; i++)
    {
        if (score[i - 1] > maxValue)
        {
            maxValue = score[i - 1];
            maxIndex = i - 1;
        }
    }
    capitalize(candidates[maxIndex]);
    printf("%s\n", candidates[maxIndex]);

    free(score);
    free(candidates);
    free(newString);

    return 0;
}

bool checkCandidate(string vote, int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        if(stringCompare(upperString(vote),upperString(argv[i]))){
            return true;
        }
    }
    return false;
}

int voteCandidate(char **candidate, char *vote, int numberOfCandidate)
{
    for (int i = 0; i < numberOfCandidate; i++)
    {
        if(stringCompare(upperString(candidate[i]),upperString(vote))){
            return i;
        }
    }
    return -1;
}

char *upperString(char *s)
{
    for (int i = 0; i < stringLength(s); i++)
    {
        if (s[i] <= 90)
        {
            s[i] = s[i] + 32;
        }
    }
    return s;
}
void capitalize(char *s)
{
    if (s[0] > 90)
    {
        s[0] = s[0] - 32;
    }
    for (int i = 1; i < stringLength(s); i++)
    {
        if (s[i] <= 90)
        {
            s[i] = s[i] + 32;
        }
    }
}
char *removeSpace(char *s)
{
    int newSize = 0;
    for (int i = 0; i < stringLength(s); i++)
    {
        if (s[i] != ' ')
        {
            newSize++;
        }
    }

    newString = malloc(newSize + 1);
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
    if (stringLength(s1) != stringLength(s2))
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

int stringLength(char *s)
{
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
