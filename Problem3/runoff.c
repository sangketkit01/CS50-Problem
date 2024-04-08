#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX_CANDIDATE 9
#define MAX_VOTERS 100

int preferences [MAX_VOTERS][MAX_CANDIDATE];

typedef struct{
    char* name;
    int votes;
    bool eliminated;
}
Candidate;

Candidate candidates[MAX_CANDIDATE];

int voter_count,candidate_count;

bool vote(int voter,int rank,char* name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc,char** argv){
    if(argc<2){
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc-1;
    if(candidate_count>MAX_CANDIDATE){
        printf("Maximum of candidate is %i\n",MAX_CANDIDATE);
        return 1;
    }

    for(int i = 0 ;i<candidate_count;i++){
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if(voter_count > MAX_VOTERS){
        printf("Maximum of voters is %i\n",MAX_VOTERS);
        return 1;
    }

    for(int i = 0 ;i<voter_count;i++){
        for(int j = 0 ; j<candidate_count ; j++){
            char* vote_name = get_string("Rank %d: ",j+1);

            if(!vote(i,j,vote_name)){
                printf("Invalid vote.\n");
            }
        }
        printf("\n");
    }

    while(true){
        tabulate();

        bool won = print_winner();
        if(won){
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        if(tie){
            for(int i = 0;i<candidate_count;i++){
                if(!candidates[i].eliminated){
                    printf("%s\n",candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);
    }
}

bool vote(int voter,int rank,char* name){
    for(int i = 0 ;i<candidate_count;i++){
        if(strcmp(candidates[i].name,name) == 0){
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(void){
    for(int i = 0 ;i<voter_count;i++){
        for(int j = 0 ; j<candidate_count;j++){
           int voter_preference = preferences[i][j];
           if(candidates[voter_preference].eliminated == false){
                candidates[voter_count].votes ++;
                break;
           }
        }
    }
}

bool print_winner(void){
    int majority = voter_count/2;
    for(int i = 0 ;i<candidate_count;i++){
        if(candidates[i].votes > majority){
            printf("%s\n",candidates[i].name);
            return true;
        }
    }
    return false;
}

int find_min(void){
    int min_votes = 100;
    for(int i = 0 ;i<candidate_count;i++){
        if(candidates[i].eliminated == false){
            if(candidates[i].votes < min_votes){
                min_votes = candidates[i].votes;
            }
        }
    }
    return min_votes;
}

bool is_tie(int min){
    for(int i = 0 ;i<candidate_count;i++){
        if(candidates[i].eliminated == false){
            if(candidates[i].votes != min){
                return false;
            }
        }
    }
    return true;
}

void eliminate(int min){
    for(int i= 0 ;i<candidate_count;i++){
        if(candidates[i].eliminated == false){
            if(candidates[i].votes == min){
                candidates[i].eliminated = true;
            }
        }
    }
}
