#include "s21_matrix.h"

int s21_equal_size(matrix_t *A, matrix_t *B) {
  return ((A->rows == B->rows) && (A->columns == B->columns));
}

void s21_null_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) A->matrix[i][j] = 0;
}

int s21_squared(matrix_t *A) { return (A->rows == A->columns && A->rows > 0); }

int s21_check_equality(double elem1, double elem2) {
  int status;
  if (!isnan(elem1) && !isnan(elem2))
    status = (fabs(elem1 - elem2) < EPSILON);
  else
    status = (isnan(elem1) && isnan(elem2));
  return status;
}

int s21_check_order(matrix_t *A) { return (A->rows > 0 && A->columns > 0); }

int s21_check_nan(matrix_t *A) {
  int status = 1;
  for (int i = 0; (i < A->rows && status); i++)
    for (int j = 0; (j < A->columns && status); j++) {
      if (isnan(A->matrix[i][j])) status = 0;
    }
  return status;
}