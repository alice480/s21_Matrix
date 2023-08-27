#include "s21_tests.h"

START_TEST(calc_determ_non_quad) {
  matrix_t A;
  int rows = 3, columns = 4, status = 1;
  status = s21_create_matrix(rows, columns, &A);
  double determ = 0;
  if (!status) status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_determ_1x1_ok) {
  matrix_t A;
  int rows = 1, columns = 1, status = 1;
  status = s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  double determ = 0.1;
  if (!status) status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq((int)determ, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_determ_2x2_ok) {
  matrix_t A;
  int rows = 2, columns = 2, status = 1;
  status = s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 5;
  double determ = 0.1;
  if (!status) status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq((int)determ, 5);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_determ_3x3_ok) {
  matrix_t A;
  int rows = 3, columns = 3, status = 1;
  status = s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  double determ;
  if (!status) status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq(determ, -54);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_determ_4x4_ok) {
  matrix_t A;
  int rows = 4, columns = 4, status;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 18;
  A.matrix[0][1] = 8;
  A.matrix[0][2] = 16;
  A.matrix[0][3] = 17;
  A.matrix[1][0] = 19;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 16;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 11;
  A.matrix[2][2] = 10;
  A.matrix[2][3] = 13;
  A.matrix[3][0] = 7;
  A.matrix[3][1] = 11;
  A.matrix[3][2] = 20;
  A.matrix[3][3] = 19;
  double determ;
  status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determ, 8652);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_determ_zero) {
  matrix_t A;
  int rows = 3, columns = 3, status;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  double determ;
  status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determ, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(neg_rows) {
  matrix_t A;
  int rows = -2, columns = 2, status;
  double determ;
  s21_create_matrix(rows, columns, &A);
  status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(neg_cols) {
  matrix_t A;
  int rows = 2, columns = -2, status;
  double determ;
  s21_create_matrix(rows, columns, &A);
  status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(nan_matrix) {
  matrix_t A;
  double determ;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  status = s21_determinant(&A, &determ);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite() {
  Suite *s_determinant;
  TCase *tc_legal;

  s_determinant = suite_create("\033[45m-=S21_DETERMINANT=-\033[0m");

  tc_legal = tcase_create("suite_determinant");
  tcase_add_test(tc_legal, calc_determ_non_quad);
  tcase_add_test(tc_legal, calc_determ_1x1_ok);
  tcase_add_test(tc_legal, calc_determ_2x2_ok);
  tcase_add_test(tc_legal, calc_determ_3x3_ok);
  tcase_add_test(tc_legal, calc_determ_4x4_ok);
  tcase_add_test(tc_legal, calc_determ_zero);
  tcase_add_test(tc_legal, neg_rows);
  tcase_add_test(tc_legal, neg_cols);
  tcase_add_test(tc_legal, nan_matrix);
  suite_add_tcase(s_determinant, tc_legal);

  return s_determinant;
}
