#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (s21_check_order(A)) {
    if (s21_squared(A) && s21_check_nan(A)) {
      if (A->rows == 1)
        *result = A->matrix[0][0];
      else if (A->rows == 2)
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      else {
        matrix_t new_A;
        *result = 0;
        for (int col = 0; col < A->columns; col++) {
          double mnog = A->matrix[0][col];
          s21_new_matrix(0, col, A, &new_A);
          double det;
          s21_determinant(&new_A, &det);
          *result += s21_unit_sign(0, col) * mnog * det;
          s21_remove_matrix(&new_A);
        }
      }
    } else {
      status = CALCULATING_ERROR;
    }
  } else
    status = UNCORRECT_MATRIX;
  return status;
}

void s21_new_matrix(int row, int col, matrix_t *original, matrix_t *result) {
  s21_create_matrix(original->rows - 1, original->columns - 1, result);
  int row_shift = 0, col_shift = 0;
  for (int i = 0; i < original->rows; i++) {
    if (i != row) {
      for (int j = 0; j < original->columns; j++) {
        if (j != col) {
          result->matrix[i - row_shift][j - col_shift] = original->matrix[i][j];
        } else {
          col_shift++;
        }
      }
      col_shift = 0;
    } else {
      row_shift++;
    }
  }
}

int s21_unit_sign(int row, int col) { return (!((row + col) % 2)) ? 1 : -1; }