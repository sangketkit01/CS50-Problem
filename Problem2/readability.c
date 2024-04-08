#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void){
    int characterCount = 0;
    int wordCount = 1;
    int sentenceCount = 1;
    string sentence = get_string("Text: ");

    for (int i = 0; i <= strlen(sentence); i++){
        if (sentence[i] == '!' || sentence[i] == '.' || sentence[i] == '?'){
            sentenceCount++;
        }
        else if (sentence[i] == ' '){
            wordCount++;
        }
        else if (sentence[i] == ','){
            continue;
        }
        else{
            characterCount++;
        }
    }
    double L = ((double)characterCount / (double)wordCount) * 100;
    double S = ((double)sentenceCount / (double)wordCount) * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;


    if(index<1.00){
        printf("Before Grade 1\n");
    }else if(ceil(index)>=16.00){
        printf("Grade 16+\n");
    }else if(ceil(index)-index<=0.9){
        printf("Grade %d\n", (int)ceil(index));
    }
    else{
        printf("Grade %d\n",(int)round(index));
    }
}
