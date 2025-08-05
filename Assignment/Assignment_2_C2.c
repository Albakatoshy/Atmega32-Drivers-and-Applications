#include <stdio.h>

int num1 , num2 ,  operation = 0;

int main(){

    printf("Enter the first num: ");
    scanf("%d",&num1);
    printf("Enter the second num: ");
    scanf("%d",&num2);
    printf("1:represents addition\n2:represents subtraction\n3:represents multiplication\n4:represents division\nEnter: ");
    scanf("%d",&operation);
    
    switch (operation)
    {
    case 1:
        int sum = 0;
        sum = num1 + num2;
        printf("%d+%d = %d ",num1,num2,sum);
        break;
    case 2:
        int sub = 0;
        sub = num1 - num2;
        printf("%d-%d = %d ",num1,num2,sub);
        break;
    case 3:
        int multi = 0;
        multi = num1*num2;
        printf("%d*%d = %d ",num1,num2,multi);
        break;
    case 4:
        int div = 0;
        div = num1/num2;
        printf("%d/%d = %d ",num1,num2,div);
        break;    
    default:
        break;
    }


}