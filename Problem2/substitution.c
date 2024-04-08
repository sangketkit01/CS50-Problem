#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void replacePlainWithKey(char *plain, char *key);
bool isDuplicate(char* s);
int main(int argc, char *argv[])
{
    int count = 0;
    if(argc != 2 || isDuplicate(argv[1])){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] == ' ' || !(toupper(argv[1][i]) >= 'A' && toupper(argv[1][i]) <= 'Z')){
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else{
            count++;
        }
    }
    if (count < 26 || count > 26){
        printf("key must contain 26 characters");
        return 1;
    }
    else{
        char *plainText = get_string("plaintext: ");
        replacePlainWithKey(plainText, argv[1]);
        printf("ciphertext: %s\n", plainText);
    }

    return 0;
}
void replacePlainWithKey(char *plain, char *key){
    int letterAscii = 0;
    int isLower = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = 0; j < strlen(plain); j++)
        {

            if (!(toupper(plain[j]) >= 'A' && toupper(plain[j]) <= 'Z') || plain[j] == ' ')
            {
                continue;
            }
            if (plain[j] >= 'A' && plain[j] <= 'Z')
            {
                letterAscii = 65;
                isLower = 0;
            }
            else if (plain[j] >= 'a' && plain[j] <= 'z')
            {
                letterAscii = 97;
                isLower = 32;
            }
            *(plain + j) = toupper(key[plain[j]-letterAscii]) + isLower;
        }
        break;
    }
}
bool isDuplicate(char* s){
    for(int i = 0 ; i<strlen(s) ;i++){
        for(int j = i+1 ; j< strlen(s);j++){
            if(toupper(*(s+i)) == toupper(*(s+j))){
                return true;
            }
        }
    }
    return false;
}
