#include "s21_tests.h"

START_TEST(transpose_1x3_ok) {
  matrix_t A, R;
  int status;
  s21_create_matrix(1, 3, &A);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4.2;
  A.matrix[0][2] = 5;
  status = s21_transpose(&A, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(R.matrix[0][0], -3);
  ck_assert_double_eq(R.matrix[1][0], 4.2);
  ck_assert_double_eq(R.matrix[2][0], 5);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_3x1_ok) {
  matrix_t A, R;
  int status;
  s21_create_matrix(3, 1, &A);
  A.matrix[0][0] = -3;
  A.matrix[1][0] = 4.2;
  A.matrix[2][0] = 5;
  status = s21_transpose(&A, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq((R.matrix[0][0]), -3);
  ck_assert_double_eq((R.matrix[0][1] * 10), 42);
  ck_assert_double_eq((R.matrix[0][2]), 5);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_3x3_ok) {
  matrix_t A, R;
  int status;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 5;
  A.matrix[1][0] = -6;
  A.matrix[1][1] = 42;
  A.matrix[1][2] = 7;
  A.matrix[2][0] = -8;
  A.matrix[2][1] = 421;
  A.matrix[2][2] = 55;
  status = s21_transpose(&A, &R);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(R.matrix[0][0], -3);
  ck_assert_double_eq(R.matrix[1][0], 4);
  ck_assert_double_eq(R.matrix[2][0], 5);
  ck_assert_double_eq(R.matrix[0][1], -6);
  ck_assert_double_eq(R.matrix[1][1], 42);
  ck_assert_double_eq(R.matrix[2][1], 7);
  ck_assert_double_eq(R.matrix[0][2], -8);
  ck_assert_double_eq(R.matrix[1][2], 421);
  ck_assert_double_eq(R.matrix[2][2], 55);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_incorrect_A) {
  matrix_t A, R;
  int status;
  s21_create_matrix(1, 0, &A);
  status = s21_transpose(&A, &R);
  ck_assert_int_eq(status, UNCORRECT_MATRIX);
}
END_TEST

// START_TEST(transpose_wrong_order) {
//   matrix_t A, R;
//   int status;
//   s21_create_matrix(1, 1, &A);
//   s21_create_matrix(2, 2, &R);
//   A.matrix[0][0] = 3;
//   R.matrix[0][0] = 1;
//   R.matrix[0][1] = 2;
//   R.matrix[1][0] = 3;
//   R.matrix[1][1] = 4;
//   status = s21_transpose(&A, &R);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&R);
//   ck_assert_int_eq(status, CALCULATING_ERROR);
// }
// END_TEST

Suite *s21_transpose_suite() {
  Suite *s_transpose;
  TCase *tc_transpose;

  s_transpose = suite_create("\033[45m-=S21_TRANSPOSE=-\033[0m");

  tc_transpose = tcase_create("transpose_suite");
  tcase_add_test(tc_transpose, transpose_1x3_ok);
  tcase_add_test(tc_transpose, transpose_3x1_ok);
  tcase_add_test(tc_transpose, transpose_3x3_ok);
  tcase_add_test(tc_transpose, transpose_incorrect_A);
  // tcase_add_test(tc_transpose, transpose_wrong_order);
  suite_add_tcase(s_transpose, tc_transpose);

  return s_transpose;
}
