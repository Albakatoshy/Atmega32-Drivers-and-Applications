#include <stdio.h>

int main(){

    int num;
    int output;
    printf("Enter the Number:\n");
    scanf("%d",&num);
    for (int i = 1 ; i<=num ; i++){
        printf("%d * %d = %d\n",num,i,(num*i));
    }
    
    

    return 0;
}