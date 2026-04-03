#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num = 5;

  int *array = (int *)malloc(num * sizeof(int));

  if (array == NULL) {
    printf("Error in memory allocation\n");
    return 1;
  }

  for (int i = 0; i < num; i++) {
    array[i] = (i + i) * 10;
  }

  printf("values of the array dinamycally alocated:\n");
  for (int i = 0; i < num; i++) {
    printf("Position %d: %d\n", i, array[i]);
  }
  return 0;
}
