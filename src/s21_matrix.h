#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

// matrix comparison
#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define UNCORRECT_MATRIX 1
#define CALCULATING_ERROR 2

#define EPSILON 1e-6

#include <malloc.h>
#include <math.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// COMMON

int s21_equal_size(matrix_t *A, matrix_t *B);

void s21_null_matrix(matrix_t *A);

int s21_squared(matrix_t *A);

void s21_new_matrix(int row, int col, matrix_t *original, matrix_t *result);

int s21_unit_sign(int row, int col);

int s21_check_equality(double elem1, double elem2);

int s21_check_order(matrix_t *A);

int s21_check_nan(matrix_t *A);

#endif  // SRC_S21_MATRIX_H_