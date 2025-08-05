#include <stdio.h>

int main() {
    int x = 10, y = 20, z = 30;
    int *p = &x, *q = &y, *r = &z;

    // Print initial values
    printf("Initial values:\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("p = %p, q = %p, r = %p\n", *p, *q, *r);
    printf("*p = %d, *q = %d, *r = %d\n", *p, *q, *r);

    printf("Swapping\n");
    r = p;
    p = q;
    q = r;

    // Print values after swap
    printf("After swapping:\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("p = %p, q = %p, r = %p\n", (void*)p, (void*)q, (void*)r);
    printf("*p = %d, *q = %d, *r = %d\n", *p, *q, *r);

    return 0;
}