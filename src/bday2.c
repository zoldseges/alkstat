#include <stdio.h>

int solve(double P) {
  int M = 0;
  for(double comp_P = 1.0;
      ((1 - comp_P) <= P) && (M < 365);
      ++M) {
    comp_P *= (365 - M) / 365.0L;
  }

  return M;
}

int main(int argc, char *argv) {
  double P;
  scanf("%lf", &P);
  int M = solve(P);
  printf("%d\n", M);
  return 0;
}
