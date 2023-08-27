#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if ((rows > 0) && (columns > 0)) {
    double **pointers = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
      pointers[i] = (double *)malloc(columns * sizeof(double));
    result->rows = rows;
    result->columns = columns;
    result->matrix = pointers;
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) result->matrix[i][j] = NAN;
  } else {
    status = UNCORRECT_MATRIX;
    result->rows = 0;
    result->columns = 0;
    result->matrix = NULL;
  }
  return status;
}
