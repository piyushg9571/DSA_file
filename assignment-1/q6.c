//Q-6) Write a c program to display the content of pointers using arrays of pointers.
#include <stdio.h>
int main() {
    int num1 = 10, num2 = 20, num3 = 30;
    int *ptrArr[3]; // Array of pointers to integers
    // Assigning addresses of variables to pointers in the array
    ptrArr[0] = &num1;
    ptrArr[1] = &num2;
 ptrArr[2] = &num3;
  // Displaying the content of pointers
    printf("Content of pointers using array of pointers:\n");
    for (int i = 0; i < 3; i++) {
        printf("Pointer %d: %d\n", i+1, *(ptrArr[i]));
    }
    return 0;
}
