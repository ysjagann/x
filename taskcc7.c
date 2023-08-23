#include <stdio.h>
#include <math.h>

int main() {
  int n, i, j;
  int marked[100];

  // Initialize all the numbers as unmarked.
  for (i = 2; i <= 100; i++) {
    marked[i] = 0;
  }

  // Start with 2 and mark all its multiples as composites.
  for (i = 2; i <= sqrt(100); i++) {
    if (!marked[i]) {
      for (j = i * i; j <= 100; j += i) {
        marked[j] = 1;
      }
    }
  }

  // Print all the unmarked numbers as primes.
  for (i = 2; i <= 100; i++) {
    if (!marked[i]) {
      printf("%d\n", i);
    }
  }

  return 0;
}
