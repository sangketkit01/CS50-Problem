#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX 9

typedef struct {
    string name;
    int votes;
}
Candidate;

Candidate candidates[MAX];
int candidate_count;

bool vote(string name);
void print_winner(void);
int main(int argc,char* argv[]){
    if(argc<2){
        printf("Usage: phurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc-1;
    if(candidate_count>MAX){
        printf("Maximum number of candidates is %d\n",MAX);
        return 2;
    }
    for(int i = 0 ;i<candidate_count;i++){
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
    }

    int voters = get_int("Number of voters: ");
    for(int i = 0;i<voters;i++){
        string voteCandidate = get_string("Vote: ");
        if(!vote(voteCandidate)){
            printf("Invalid vote.\n");
        }
    }
    print_winner();
    return 0 ;
}
bool vote(string name){
    for(int i = 0 ;i<candidate_count ; i++){
        if(strcmp(name,candidates[i].name) == 0){
            candidates[i].votes++;
            return true;
        }
    }
     return false;
}
void print_winner(void){
    int maxVote = 0;
    for(int i = 0 ;i<candidate_count;i++){
        if(candidates[i].votes>maxVote){
            maxVote = candidates[i].votes;
        }
    }
    for(int i = 0 ;i<candidate_count;i++){
        if(candidates[i].votes == maxVote){
            printf("%s\n",candidates[i].name);
        }
    }
}
