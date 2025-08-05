#include <stdio.h>

int main() {
    int answer;
    int correct_result = 7 + 8; // Example: 7 * 8

    printf("Alarm System: Solve the following to stop the alarm!\n");
    printf("What is 7 + 8?\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    while (answer != correct_result) {
        printf("Incorrect! Try again.\n");
        printf("Enter your answer: ");
        scanf("%d", &answer);
    }

    printf("Correct! Alarm stopped.\n");


    return 0;

}
