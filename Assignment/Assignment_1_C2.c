#include <stdio.h>

int num1 , num2 ,  num3 = 0;

int main(){
    printf("Enter the first num: ");
    scanf("%d",&num1);
    printf("Enter the second num: ");
    scanf("%d",&num2);
    printf("Enter the third num: ");
    scanf("%d",&num3);

    if(num1 > num2 && num1 > num3){
        printf("The Greatest Number = %d ",num1);
    }
    else if (num2 > num2 && num1 > num3)
    {
         printf("The Greatest Number = %d ",num2);
    }
    else if (num3 > num2 && num3 > num1)
    {
         printf("The Greatest Number = %d ",num3);
    }
    
    

}