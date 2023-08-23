#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform modular exponentiation (a^b % m)
int modular_pow(int base, int exponent, int modulus) {
    int result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

// Fermat's primality test function
int fermat_primality_test(int n, int k) {
	int i;
    if (n <= 1) {
        return 0; // Not prime
    }
    
    if (n <= 3) {
        return 1; // 2 and 3 are prime
    }
    
    // Repeat the test for k random values of 'a'
    for ( i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 2); // Random number in [2, n-1]
        
        // If a^(n-1) % n is not 1, then n is composite
        if (modular_pow(a, n - 1, n) != 1) {
            return 0; // Not prime
        }
    }
    
    return 1; // Probably prime
}

int main() {
    int n, k;

    // Get the number to be tested.
    printf("Enter a number: ");
    scanf("%d", &n);

    // Get the number of iterations.
    printf("Enter the number of iterations: ");
    scanf("%d", &k);

    // Seed the random number generator
    srand(time(NULL));

    if (fermat_primality_test(n, k)) {
        printf("%d is probably prime.\n", n);
    } else {
        printf("%d is composite.\n", n);
    }

    return 0;
}

