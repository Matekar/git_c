#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(void) {
  int *tab = malloc(sizeof(int));
  if (!tab) {
    free(tab);
    return -1;
  }

  *tab = 1;

  for (int j = 1; j < SIZE; j++) {
    tab = realloc(tab, (j + 1) * sizeof(int));
    if (!tab) {
      free(tab);
      return -1;
    }

    tab[(j + 1) * sizeof(int) - 1] = 1;
    for (int i = j - 1; i > 0; i--)
      tab[i] = tab[i - 1] + tab[i];
    for (int i = 0; i < j; i++)
      printf("%4d", tab[i]);
    printf("\n");
  }

  free(tab);
  return 0;
}