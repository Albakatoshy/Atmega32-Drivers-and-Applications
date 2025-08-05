#include <stdio.h>

int main() {
    int arr[100], n, i;
    int sum_even = 0, sum_odd = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            sum_even += arr[i];
        else
            sum_odd += arr[i];
    }

    printf("Sum of even numbers: %d\n", sum_even);
    printf("Sum of odd numbers: %d\n", sum_odd);

    return 0;
}