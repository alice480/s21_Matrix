#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (s21_check_order(A)) {
    if (s21_squared(A) && s21_check_nan(A)) {
      double det;
      s21_determinant(A, &det);
      if (det) {
        matrix_t alg_additions_mx, transpose_mx;
        s21_calc_complements(A, &alg_additions_mx);
        s21_transpose(&alg_additions_mx, &transpose_mx);
        s21_mult_number(&transpose_mx, 1 / det, result);
        // remove auxilary matrix
        s21_remove_matrix(&alg_additions_mx);
        s21_remove_matrix(&transpose_mx);
      } else {
        status = CALCULATING_ERROR;
      }
    } else
      status = CALCULATING_ERROR;
  } else
    status = UNCORRECT_MATRIX;
  return status;
}