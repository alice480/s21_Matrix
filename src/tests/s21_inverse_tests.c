#include "s21_tests.h"

START_TEST(calc_inverse_ok) {
  matrix_t A, R;
  int rows = 3, columns = 3, status = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  status = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq((int)(R.matrix[0][0]), 1);
  ck_assert_int_eq((int)(R.matrix[0][1]), -1);
  ck_assert_int_eq((int)(R.matrix[0][2]), 1);
  ck_assert_int_eq((int)(R.matrix[1][0]), -38);
  ck_assert_int_eq((int)(R.matrix[1][1]), 41);
  ck_assert_int_eq((int)(R.matrix[1][2]), -34);
  ck_assert_int_eq((int)(R.matrix[2][0]), 27);
  ck_assert_int_eq((int)(R.matrix[2][1]), -29);
  ck_assert_int_eq((int)(R.matrix[2][2]), 24);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(calc_inverse_identity_mx) {
  matrix_t A, R, ID;
  int rows = 3, columns = 3, status = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2.38;
  A.matrix[0][1] = 5.17;
  A.matrix[0][2] = 7.26;
  A.matrix[1][0] = 6.49;
  A.matrix[1][1] = 3.55;
  A.matrix[1][2] = 4.64;
  A.matrix[2][0] = 5.73;
  A.matrix[2][1] = -2.82;
  A.matrix[2][2] = -3.94;
  status = s21_inverse_matrix(&A, &R);
  s21_mult_matrix(&A, &R, &ID);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq((int)(ID.matrix[0][0]), 1);
  ck_assert_int_eq((int)(ID.matrix[0][1]), 0);
  ck_assert_int_eq((int)(ID.matrix[0][2]), 0);
  ck_assert_int_eq((int)(ID.matrix[1][0]), 0);
  ck_assert_int_eq((int)(ID.matrix[1][1]), 1);
  ck_assert_int_eq((int)(ID.matrix[1][2]), 0);
  ck_assert_int_eq((int)(ID.matrix[2][0]), 0);
  ck_assert_int_eq((int)(ID.matrix[2][1]), 0);
  ck_assert_int_eq((int)(ID.matrix[2][2]), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&ID);
}
END_TEST

START_TEST(calc_inverse_imposible_det_zero) {
  matrix_t A, R;
  int rows = 3, columns = 3, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &R);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  status = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(calc_inverse_non_quad) {
  matrix_t A, R;
  int rows = 3, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  status = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(neg_rows) {
  matrix_t A, R;
  int rows = -2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &R);
  status = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(neg_cols) {
  matrix_t A, R;
  int rows = 2, columns = -2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &R);
  status = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(nan_matrix) {
  matrix_t A, R;
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &R);
  status = s21_inverse_matrix(&A, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  ck_assert_int_eq(status, CALCULATING_ERROR);
}
END_TEST

Suite *s21_inverse_suite() {
  Suite *s_inverse;
  TCase *tc_legal;

  s_inverse = suite_create("\033[45m-=S21_INVERSE_MARTIX=-\033[0m");

  tc_legal = tcase_create("inverse_suite");
  tcase_add_test(tc_legal, calc_inverse_ok);
  tcase_add_test(tc_legal, calc_inverse_identity_mx);
  tcase_add_test(tc_legal, calc_inverse_imposible_det_zero);
  tcase_add_test(tc_legal, calc_inverse_non_quad);
  tcase_add_test(tc_legal, neg_rows);
  tcase_add_test(tc_legal, neg_cols);
  tcase_add_test(tc_legal, nan_matrix);
  suite_add_tcase(s_inverse, tc_legal);

  return s_inverse;
}
