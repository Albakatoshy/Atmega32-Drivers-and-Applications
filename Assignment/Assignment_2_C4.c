#include <stdio.h>

int factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);

    if (n >= r && n >= 0 && r >= 0) {
        printf("nCr = %d\n", nCr(n, r));
    } else {
        printf("Invalid \n");

    }
    return 0;
}