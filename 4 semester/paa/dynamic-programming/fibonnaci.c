#include <stdio.h>
#include <stdlib.h>

int top_down(int *table, int n);
int bottom_up(int n);
int main(int argc, char *argv[]) {

  int n;
  scanf("%d", &n);

  /// table that will stores the values. Each index corresponds to
  /// its fibonacci solution(index 2 holds fib(2)), so it is possible to provide
  /// O(1) acess.
  int *table = calloc(n + 1, sizeof(int));
  table[0] = 0;
  table[1] = 1;

  printf("Solution using top-down approach: %d", top_down(table, n));
  printf("\n Solution using bottom-up approach: %d", bottom_up(n));
  return 0;
}
///
/// Solves fibonnaci problem using a top_down approach. The
/// top-down approach in fibonacci consists in stores the solutions
/// in a table for acess.
int top_down(int *table, int n) {

  if (n == 0)
    return 0;
  /// means it was previously solved
  if (table[n] != 0)
    return table[n];

  table[n] = top_down(table, n - 2) + top_down(table, n - 1);
  return table[n];
}

/// Solves the fibonnaci sequence using a bottom_up approach.
/// This bottom_up approach solves smaller problems and stores them
/// for future use
int bottom_up(int n) {
  int *table = calloc(n + 1, sizeof(int));
  table[0] = 0;
  table[1] = 1;

  for (int i = 2; i < n + 1; i++) {
    table[i] = table[i - 2] + table[i - 1];
  }

  return table[n];
}
