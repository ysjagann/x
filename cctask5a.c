#include <stdio.h>

// Function to return gcd of a and b
int gcd(int a, int b) {
    // Find the Minimum of a and b
    int result = (a < b) ? a : b;

    while (result > 0) {
        // Use the correct comparison operators: == instead of =
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}

int main() {
    int a = 98, b = 56; // Added commas to separate variable assignments
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b)); // Corrected the printf statement
    return 0;
}

