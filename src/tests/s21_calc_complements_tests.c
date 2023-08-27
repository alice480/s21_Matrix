#include "s21_tests.h"

START_TEST(complements_fail_rows_A) {
  matrix_t A, R;
  int columns = 3, status = 0;
  s21_create_matrix(0, columns, &A);
  status = s21_calc_complements(&A, &R);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(complements_fail_1x1) {
  matrix_t A, R;
  int columns = 1, rows = 1, status = 0;
  s21_create_matrix(rows, columns, &A);
  status = s21_calc_complements(&A, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_fail_A_quad) {
  matrix_t A, R;
  int rows = 3, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  status = s21_calc_complements(&A, &R);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_3x3_ok) {
  matrix_t A, R;
  int rows = 3, columns = 3, status = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  status = s21_calc_complements(&A, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(R.matrix[0][0], 0);
  ck_assert_int_eq(R.matrix[0][1], 10);
  ck_assert_int_eq(R.matrix[0][2], -20);
  ck_assert_int_eq(R.matrix[1][0], 4);
  ck_assert_int_eq(R.matrix[1][1], -14);
  ck_assert_int_eq(R.matrix[1][2], 8);
  ck_assert_int_eq(R.matrix[2][0], -8);
  ck_assert_int_eq(R.matrix[2][1], -2);
  ck_assert_int_eq(R.matrix[2][2], 4);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(nan_matrix) {
  matrix_t A, R;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  status = s21_calc_complements(&A, &R);
  s21_remove_matrix(&A);
  ck_assert_int_eq(status, CALCULATING_ERROR);
}
END_TEST

Suite *s21_calc_complements_suite() {
  Suite *s_calc_complements;
  TCase *tc_legal;

  s_calc_complements = suite_create("\033[45m-=S21_CALC_COMPLEMENTS=-\033[0m");

  tc_legal = tcase_create("calc_complements_suite");
  tcase_add_test(tc_legal, complements_fail_rows_A);
  tcase_add_test(tc_legal, complements_fail_1x1);
  tcase_add_test(tc_legal, complements_fail_A_quad);
  tcase_add_test(tc_legal, complements_3x3_ok);
  tcase_add_test(tc_legal, nan_matrix);

  suite_add_tcase(s_calc_complements, tc_legal);

  return s_calc_complements;
}
