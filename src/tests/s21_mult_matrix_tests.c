#include "s21_tests.h"

START_TEST(mult_matrix_3x2_x_2x3_ok) {
  matrix_t A, B, R;
  int rows = 3, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq((R.matrix[0][0]), 9);
  ck_assert_double_eq((R.matrix[0][1]), 11);
  ck_assert_double_eq((R.matrix[0][2]), 17);
  ck_assert_double_eq((R.matrix[1][0]), 12);
  ck_assert_double_eq((R.matrix[1][1]), 13);
  ck_assert_double_eq((R.matrix[1][2]), 22);
  ck_assert_double_eq((R.matrix[2][0]), 15);
  ck_assert_double_eq((R.matrix[2][1]), 15);
  ck_assert_double_eq((R.matrix[2][2]), 27);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_1x2_x_2x1_ok) {
  matrix_t A, B, R;
  int status = 0;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  B.matrix[0][0] = 3;
  B.matrix[1][0] = 2;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq((R.matrix[0][0]), 11);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_2x1_x_1x2_ok) {
  matrix_t A, B, R;
  int status = 0;
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 4;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 2;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq((R.matrix[0][0]), 3);
  ck_assert_double_eq((R.matrix[0][1]), 2);
  ck_assert_double_eq((R.matrix[1][0]), 12);
  ck_assert_double_eq((R.matrix[1][1]), 8);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_2x2_x_2x2_ok) {
  matrix_t A, B, R;
  int status = 0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 5;
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 1;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq((R.matrix[0][0]), 22);
  ck_assert_double_eq((R.matrix[0][1]), 6);
  ck_assert_double_eq((R.matrix[1][0]), 38);
  ck_assert_double_eq((R.matrix[1][1]), 11);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_1x2_x_2x2_ok) {
  matrix_t A, B, R;
  int status = 0;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq((R.matrix[0][0]), 34);
  ck_assert_double_eq((R.matrix[0][1]), 26);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_2x2_x_2x1_ok) {
  matrix_t A, B, R;
  int status = 0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 1, &B);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 2;
  B.matrix[0][0] = 4;
  B.matrix[1][0] = 5;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq((R.matrix[0][0]), 32);
  ck_assert_double_eq((R.matrix[1][0]), 34);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_1x2_x_3x2_calc_error) {
  matrix_t A, B, R;
  int status = 0;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 2, &B);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[2][0] = 6;
  B.matrix[2][1] = 7;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_1x2_x_2x2_3x3_calc_error) {
  matrix_t A, B, R;
  int status = 0;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 2, &B);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(neg_rows) {
  matrix_t A, B, R;
  s21_create_matrix(-2, 2, &A);
  s21_create_matrix(2, 2, &B);
  int status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(neg_cols) {
  matrix_t A, B, R;
  s21_create_matrix(2, -2, &A);
  s21_create_matrix(2, 2, &B);
  int status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_nan) {
  matrix_t A, B, R;
  int status = 0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 1, &B);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 2;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_mult_matrix_suite() {
  Suite *s_mult_matrix;
  TCase *tc_legal;

  s_mult_matrix = suite_create("\033[45m-=S21_MULT_MATRIX=-\033[0m");

  tc_legal = tcase_create("mult_matrix matrix");
  tcase_add_test(tc_legal, mult_matrix_3x2_x_2x3_ok);
  tcase_add_test(tc_legal, mult_matrix_1x2_x_2x1_ok);
  tcase_add_test(tc_legal, mult_matrix_2x1_x_1x2_ok);
  tcase_add_test(tc_legal, mult_matrix_2x2_x_2x2_ok);
  tcase_add_test(tc_legal, mult_matrix_1x2_x_2x2_ok);
  tcase_add_test(tc_legal, mult_matrix_2x2_x_2x1_ok);
  tcase_add_test(tc_legal, mult_matrix_1x2_x_3x2_calc_error);
  tcase_add_test(tc_legal, mult_matrix_1x2_x_2x2_3x3_calc_error);
  tcase_add_test(tc_legal, neg_rows);
  tcase_add_test(tc_legal, neg_cols);
  tcase_add_test(tc_legal, mult_matrix_nan);
  suite_add_tcase(s_mult_matrix, tc_legal);

  return s_mult_matrix;
}
