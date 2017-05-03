#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_DATA_FILE "in.txt"
#define OUTPUT_DATA_FILE "out.txt"

void insertion_sort(int *a, int t)
{
  int i, j, temp;
  for (i = 1; i < t; i++)
  {
    temp = a[i];
    j = i - 1;
    while ((j >= 0) && (a[j] < temp))
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
  }
}
void print_matrix(int matrix_size, int matrix[100][100])
{
  int i, j;
  for (i = 0; i < matrix_size; i++)
  {
    for (j = 0; j < matrix_size; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  FILE *f;
  if ((f = fopen(INPUT_DATA_FILE, "r")) == NULL)
  {
    printf("Can't open the file '%s'\n", INPUT_DATA_FILE);
    exit(1);
  }

  int i, j, m, n, a[100][100], s[100], t = 0;
  char c;
  int matrix_size = 0;
  while ((c = getc(f)) != EOF)
  {
    ungetc(c, f);
    fscanf(f, "%d", &matrix_size);
    for (i = 0; i < matrix_size; i++)
    {
      for (j = 0; j < matrix_size; j++)
      {
        fscanf(f, "%d", &a[i][j]);
      }
    }
  }
  fclose(f);

  printf("Matrix size:[%d*%d]\n Raw matrix:\n", matrix_size, matrix_size);

  print_matrix(matrix_size, a);
  for (j = 1; j < matrix_size - 1; j++)
  {
    // read diagonal row
    for (i = 0; i < matrix_size - j; i++)
    {
      s[t] = a[i][i + j];
      printf("s[t]:%d , t:%d\n", s[t],t);
      t++;
    }

    // sort diagonal
    insertion_sort(s, t);
    t = 0;

    // save sorted diagonal into the original matrix
    for (i = 0; i < matrix_size - j; i++)
    {
      a[i][j + i] = s[t];
      printf("a[t]:%d , t:%d\n", a[t],t);
      t++;
    }
    t = 0;
  }
  printf("Sorted matrix: %d %d \n", matrix_size, matrix_size);

  print_matrix(matrix_size, a);

  FILE *fp;
  if ((fp = fopen(OUTPUT_DATA_FILE, "w")) != NULL)
  {
    fprintf(fp, "%d\n", matrix_size);
    for (i = 0; i < matrix_size; i++)
    {
      for (j = 0; j < matrix_size; j++)
      {
        fprintf(fp, "%d ", a[i][j]);
      }
      fprintf(fp, "\n");
    }
    fclose(fp);
  }
  else
  {
    printf("Can't open the file '%s'\n", OUTPUT_DATA_FILE);
    exit(1);
  }
}
