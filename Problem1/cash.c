#include <stdio.h>
#include <cs50.h>

int main(void){
    int count = 0;
    int coins[] = {1,5,10,25};
    while(true){
        int changed = get_int("Change owned: ");
        if(changed <= 0){
            continue;
        }
        else{
            for(int i = 3 ; i>=0 ;i--){
                if(changed <= 0){
                    break;
                }
                int temp = changed / coins[i];
                count += changed / coins[i];
                changed -= temp * coins[i];
            }
            break;
        }
    }
    printf("%d\n",count);
}
