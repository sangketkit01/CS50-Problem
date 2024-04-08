#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkScore(string s);
int main(void){
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    if(checkScore(player1) > checkScore(player2)){
        printf("Player 1 Wins!\n");
    }
    else if(checkScore(player1) < checkScore(player2)){
        printf("Player 2 wins!\n");
    }else{
        printf("Tie!");
    }
}
int checkScore(string s){
    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int numbers[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;
    for(int i = 0 ; i < strlen(characters) ; i++){
        for(int j = 0 ; j < strlen(s) ; j++){
            if(tolower(s[j]) == tolower(characters[i])){
                score += numbers[i];
            }
        }
    }
    return score;
}
