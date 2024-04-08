#include <stdio.h>
#include <cs50.h>

int main(void){
    while(true){
    int h = get_int("Height: ");
    if(h<=0){
        continue;
    }else{
        for(int i = 1 ; i<=h ; i++){
            for (int k = 1; k <= h - i; k++) {
                printf(" ");
          }
            for(int j = 1;j<=i;j++){
                printf("#");
            }
            printf("\n");
        }
        break;
    }
}
}
