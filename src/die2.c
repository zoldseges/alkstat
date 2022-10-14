#include <stdio.h>
#include <assert.h>

void walk_tree(int *arr, int acc, int depth, int max_depth) {
  if (depth == max_depth) {
    arr[acc]++;
  } else {
    depth++;
    for(int i = 1; i < 7; ++i) {
      walk_tree(arr, acc + i, depth, max_depth);
    }
  }
}

int solve_and_print(int P) {
  assert(P > 0 && P < 55);
  // n ... 6P == 5P
  int size = (6 * P) + 1;
  int arr[512] = {0};
  int sum = 0;
  walk_tree(arr, 0, 0, P);
  for(int i = 0; i < size; ++i) {
    sum += arr[i];
  }
  for(int i = P; i < size; ++i) {
    printf("%f\n", (double)arr[i] / sum);
  }
  
}

int main(int argc, char *argv) {
  int P;
  scanf("%d", &P);
  solve_and_print(P);
  return 0;
}
