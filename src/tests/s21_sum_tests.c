#include "s21_tests.h"

START_TEST(sum_matrix_ok) {
  matrix_t A, B, R;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 5;
  B.matrix[1][1] = 6;
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(R.matrix[0][0], 0);
  ck_assert_double_eq_tol(R.matrix[0][1], 8.2, EPSILON);
  ck_assert_double_eq(R.matrix[1][0], 10);
  ck_assert_double_eq(R.matrix[1][1], 12);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(neg_rows) {
  matrix_t A, B, R;
  int rows = -2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(neg_cols) {
  matrix_t A, B, R;
  int rows = 2, columns = -2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(nan_matrix) {
  matrix_t A, B, R;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_not_equal_rows) {
  matrix_t A, B, R;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns, &B);
  status = s21_sum_matrix(&A, &B, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(status, CALCULATING_ERROR);
}
END_TEST

START_TEST(not_equal_cols) {
  matrix_t A, B, R;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns + 1, &B);
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_sum_suite() {
  Suite *s_sum;
  TCase *tc_legal;

  s_sum = suite_create("\033[45m-=S21_SUM_MATRIX=-\033[0m");

  tc_legal = tcase_create("sum_suite");
  tcase_add_test(tc_legal, sum_matrix_ok);
  tcase_add_test(tc_legal, neg_rows);
  tcase_add_test(tc_legal, neg_cols);
  tcase_add_test(tc_legal, sum_not_equal_rows);
  tcase_add_test(tc_legal, not_equal_cols);
  tcase_add_test(tc_legal, nan_matrix);
  suite_add_tcase(s_sum, tc_legal);

  return s_sum;
}
