#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if (s21_check_order(A) && s21_check_order(B)) {
    if (s21_equal_size(A, B)) {
      for (int i = 0; ((i < A->rows) && (status == SUCCESS)); i++)
        for (int j = 0; ((j < A->columns) && (status == SUCCESS)); j++)
          status *= s21_check_equality(A->matrix[i][j], B->matrix[i][j]);
    } else
      status = FAILURE;
  } else
    status = FAILURE;
  return status;
}