#include <stdio.h>


int main(){
    int asnwer;
    int val = 8;

    printf("alarm!!\n");
    do{
        printf("5 + 3 = ");
        scanf("%d",&asnwer);
        if(asnwer!=val){
            printf("Incorrect try again..\n");
        }
    }
    while(asnwer!=val);
    printf("Correct");

    return 0;
}