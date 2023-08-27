#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (s21_check_order(A) && s21_check_order(B)) {
    if (A->columns == B->rows && s21_check_nan(A) && s21_check_nan(B)) {
      s21_create_matrix(A->rows, B->columns, result);
      s21_null_matrix(result);
      for (int row = 0; (row < A->rows && status == OK); row++)
        for (int col = 0; (col < B->columns && status == OK); col++)
          for (int k = 0; (k < A->columns && status == OK); k++)
            result->matrix[row][col] += A->matrix[row][k] * B->matrix[k][col];
    } else
      status = CALCULATING_ERROR;
  } else
    status = UNCORRECT_MATRIX;
  return status;
}
