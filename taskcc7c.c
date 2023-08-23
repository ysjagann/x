#include <stdio.h>
#include <stdlib.h>

int modular_pow(unsigned int base, unsigned int exponent, unsigned int modulus) {
  unsigned int result = 1;

  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % modulus;
    }
    base = (base * base) % modulus;
    exponent /= 2;
  }

  return result;
}

int miller_rabin(unsigned int n, int k) {
	int i,j;
  if (n == 2) {
    return 1;
  } else if (n % 2 == 0) {
    return 0;
  }

  unsigned int s = 0;
  unsigned int d = n - 1;
  while (d % 2 == 0) {
    s++;
    d >>= 1;
  }

  for (i = 0; i < k; i++) {
    unsigned int a = rand() % (n - 2) + 2;
    unsigned int x = modular_pow(a, d, n);

    if (x == 1 || x == n - 1) {
      continue;
    }

    for ( j = 0; j < s - 1; j++) {
      x = modular_pow(x, 2, n);
      if (x == 1) {
        return 0;
      } else if (x == n - 1) {
        break;
      }
    }

    if (x != n - 1) {
      return 0;
    }
  }

  return 1;
}

int main() {
  unsigned int n;
  int k;

  printf("Enter a number: ");
  scanf("%u", &n);

  printf("Enter the number of iterations: ");
  scanf("%d", &k);

  if (miller_rabin(n, k)) {
    printf("%u is probably prime.\n", n);
  } else {
    printf("%u is composite.\n", n);
  }

  return 0;
}

