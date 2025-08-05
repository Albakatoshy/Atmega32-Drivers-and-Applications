#include <stdio.h>


int main() {
    int arr[100], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    int left, right, mid, key, index;
    for (i = 1; i < n; i++) {
        key = arr[i];
        left = 0;
        right = i - 1;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (key < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        index = left;
        for (j = i - 1; j >= index; j--) {
            arr[j + 1] = arr[j];
        }
        arr[index] = key;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Min: %d\n", arr[0]);
    printf("Max: %d\n", arr[n - 1]);

    return 0;
}