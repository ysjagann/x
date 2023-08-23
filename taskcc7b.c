#include <stdio.h>
#include <stdlib.h>

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

int main() {
  int n, k, i, a;
  int is_prime = 1;

  // Get the number to be tested.
  printf("Enter a number: ");
  scanf("%d", &n);

  // Get the number of iterations.
  printf("Enter the number of iterations: ");
  scanf("%d", &k);

  // For each iteration, choose a random number a in the range 1 < a < n.
  for (i = 0; i < k; i++) {
    a = rand() % (n - 1) + 1;

    // If a^(n - 1) = 1 (mod n), then n is probably prime.
    if (modular_pow(a, n - 1, n) != 1) {
      is_prime = 0;
      break;
    }
  }

  // If is_prime is 1, then n is probably prime. Otherwise, n is composite.
  if (is_prime) {
    printf("%d is probably prime.\n", n);
  } else {
    printf("%d is composite.\n", n);
  }

  return 0;
}

