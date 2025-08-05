#include <stdio.h>

int factorial(int n) {
    unsigned long long result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int nPr(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int main() {
    int n, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);

    if (n >= r && n >= 0 && r >= 0) {
        printf("nPr = %d\n", nPr(n, r));
    } else {
        printf("Invalid input! n and r must be non-negative and n >= r.\n");
    }

    return 0;
}