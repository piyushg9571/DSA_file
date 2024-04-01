
#include<stdio.h>
int main() {
    int limit;
    printf("Enter a limit: ");
    scanf("%d", &limit);

    int a[limit], i, searchkey;

    for (i = 0; i < limit; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter a number to search: ");
    scanf("%d", &searchkey);

    for (i = 0; i < limit; i++) {
        if (searchkey == a[i]) {
            printf("The number is present at : %d", i + 1);
            break;
        }
    }

    if (i == limit) {
        printf("The number is not present in the array.");
    }
