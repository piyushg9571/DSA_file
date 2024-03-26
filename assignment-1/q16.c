//Q-16) You have a row of binary digits arranged randomly . Arrange them in such an order that all 0’s precede all I’s or vice versa. The only constraints in arranging them is that you are allowed to interchange the positions of binary digits if they are not similar . Write a program in c using the pointer to solve the problem.
//Eg: 11010100- 00001111 OR 11110000
#include <stdio.h>
void arrangeBinary(char *binary) {
    char *start = binary; // Pointer to the start of the binary array
    char *end = binary;   // Pointer to the end of the binary array
    // Move the 'end' pointer to the last non-null character
    while (*end != '\0') {
        end++;
    }
    end--;
    // Swap the positions of 0's and 1's using pointers
    while (start < end) {
        // Find the first '0' from the start
        while (*start != '0' && start < end) {
            start++;
        }
        // Find the first '1' from the end
        while (*end != '1' && start < end) {
            end--;
        }
        // Swap '0' and '1'
        if (start < end) {
            char temp = *start;
            *start = *end;
            *end = temp;
        }
    }
}
int main() {
    char binary[] = "11010100";
    printf("Original binary sequence: %s\n", binary);
    // Call the function to arrange binary digits
    arrangeBinary(binary);
    printf("Arranged binary sequence: %s\n", binary);
    return 0;
}
