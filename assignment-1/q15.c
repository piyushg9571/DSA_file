//Q-15) Write a program in c to create an array of 10 elements. 
//Take 10 elements in the array pass them into function that prints them in reverse order.
#include <stdio.h>
// Function to print elements of an array in reverse order
void Reverse(int arr[], int size) {
    printf("Elements in reverse order:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    // Declare an array of 10 elements
    int Arr[10];
    // Input 10 elements into the array
    for (int i = 0; i < 10; i++) {
        printf("Enter  element %d:\n",i+1);
        scanf("%d", &Arr[i]);
    }
    // Call the function to print elements in reverse order
    Reverse(Arr, 10);
    return 0;
}
