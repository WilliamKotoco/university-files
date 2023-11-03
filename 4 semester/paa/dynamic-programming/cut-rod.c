#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 10
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int brute_force(int);

int top_down(int *, int);

int bottom_up(int, int *);

int prices[LIMIT] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  if (n > LIMIT) {
    puts("please do not put values greater than 10");
    exit(1);
  }

  printf("Value using brute_force solution: %d", brute_force(n));

  int table[LIMIT + 1];
  for (int i = 0; i <= n + 1; i++)
    table[i] = -1;

  printf("\n Value using top-down approach: %d", top_down(table, n));
  printf("\n Value using bottom-up approach: %d", bottom_up(n, table));
  return 0;
}

int brute_force(int n) {
  if (n == 0)
    return 0;

  int aux = INT_MIN;

  for (int i = 1; i <= n; i++) {
    aux = MAX(aux, prices[i - 1] + brute_force(n - i));
  }

  return aux;
}

/// The top_down approach just adds a memoization
/// to the brute-force solution. The program will verify
/// if it was calculated previously or if it is necessary to calculate.
int top_down(int *table, int n) {
  int aux;

  if (table[n] >= 0)
    return table[n];

  if (n == 0)
    aux = 0;
  else {
    aux = INT_MIN;

    for (int i = 1; i <= n; i++)
      aux = MAX(aux, prices[i - 1] + top_down(table, n - i));

    table[n] = aux;
  }
  return aux;
}

/// uses the bottom-up approach, solving the smallers and going
/// up towards the greatests.
int bottom_up(int n, int *table) {
  /// initial value
  table[0] = 0;

  for (int i = 1; i <= n; i++) {

    int aux = INT_MIN;

    for (int j = 1; j <= i; j++) {
      aux = MAX(aux, prices[j - 1] + table[i - j]);
    }

    table[i] = aux;
  }

  return table[n];
}
