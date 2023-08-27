#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  matrix_t minor_mx;
  if (s21_check_order(A)) {
    if (s21_squared(A) && s21_check_nan(A)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++) {
          s21_new_matrix(i, j, A, &minor_mx);
          double minor = 0;
          s21_determinant(&minor_mx, &minor);
          result->matrix[i][j] = s21_unit_sign(i, j) * minor;
          s21_remove_matrix(&minor_mx);
        }
    } else
      status = CALCULATING_ERROR;
  } else
    status = UNCORRECT_MATRIX;
  return status;
}