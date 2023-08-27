#include "s21_tests.h"

START_TEST(mult_number_matrix_incorrect_A) {
  matrix_t A, R;
  double number = 5.21;
  int rows = 2, status = 0;
  s21_create_matrix(rows, -1, &A);
  status = s21_mult_number(&A, number, &R);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
}
END_TEST

// START_TEST(mult_num_not_equal_rows) {
//   matrix_t A, R;
//   int rows = 2, columns = 2, status = 0;
//   s21_create_matrix(rows + 1, columns, &A);
//   s21_create_matrix(rows, columns, &R);
//   status = s21_mult_number(&A, 1, &R);
//   ck_assert_int_eq(status, CALCULATING_ERROR);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&R);
// }
// END_TEST

// START_TEST(not_equal_cols) {
//   matrix_t A, R;
//   int rows = 2, columns = 2, status = 0;
//   s21_create_matrix(rows, columns, &A);
//   s21_create_matrix(rows, columns + 1, &R);
//   status = s21_mult_number(&A, 1, &R);
//   ck_assert_int_eq(status, CALCULATING_ERROR);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&R);
// }
// END_TEST

START_TEST(mult_number_matrix_ok) {
  matrix_t A, R;
  double number = 5.21;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  status = s21_mult_number(&A, number, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(R.matrix[0][0], -15.63, EPSILON);
  ck_assert_double_eq_tol(R.matrix[0][1], 21.882, EPSILON);
  ck_assert_double_eq_tol(R.matrix[1][0], 26.05, EPSILON);
  ck_assert_double_eq_tol(R.matrix[1][1], 31.26, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(nan_matrix) {
  matrix_t A, R;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  status = s21_mult_number(&A, 1, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_mult_number_suite() {
  Suite *s_mult_number;
  TCase *tc_mult;

  s_mult_number = suite_create("\033[45m-=S21_MULT_NUMBER_MATRIX=-\033[0m");

  tc_mult = tcase_create("mult_number matrix");
  tcase_add_test(tc_mult, mult_number_matrix_incorrect_A);
  tcase_add_test(tc_mult, mult_number_matrix_ok);
  // tcase_add_test(tc_mult, mult_num_not_equal_rows);
  // tcase_add_test(tc_mult, not_equal_cols);
  tcase_add_test(tc_mult, nan_matrix);
  suite_add_tcase(s_mult_number, tc_mult);

  return s_mult_number;
}
