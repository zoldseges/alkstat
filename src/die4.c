#include <stdio.h>
#include <math.h>

#define MAX(a, b) a > b ? a : b

void walk(int ndice, int cdice, int max, int bucket[7]) {
  if (cdice == ndice) {
    bucket[max]++;
  } else {
    cdice++;
    for (int i = 1; i < 7; ++i) {
      walk(ndice, cdice, MAX(max, i), bucket);
    }
  }
}

double solve(int n, int M) {
  int bucket[7] = {0};
  walk(n, 0, 0, bucket);
  /* for(int i = 0; i < 7; ++i) { */
  /*   printf("%d\n", bucket[i]); */
  /* } */
  int sum = 0;
  for(int i = 1; i < 7; ++i) sum += bucket[i];
  printf("%lf\n", bucket[M] / (double)sum);
}

int main(int argc, char **argv) {
  // FINAL
  int n, M;
  scanf("%d %d", &n, &M);
  double P = 0.0f;
  if(M < 7) {
    double under_M = pow(M/6.0, n);
    double under_Mminus1 = pow((M-1)/6.0, n);
    P = under_M - under_Mminus1;
  }
  printf("%f\n", P);
  return 0;
}
