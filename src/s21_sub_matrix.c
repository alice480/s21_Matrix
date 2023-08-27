#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (s21_check_order(A) && s21_check_order(B)) {
    if (s21_equal_size(A, B) && s21_check_nan(A) && s21_check_nan(B)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    } else
      status = CALCULATING_ERROR;
  } else
    status = UNCORRECT_MATRIX;
  return status;
}