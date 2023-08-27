#include "s21_tests.h"

START_TEST(neg_rows) {
  matrix_t A, B;
  int rows = -3, columns = 5, status;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(neg_cols) {
  matrix_t A, B;
  int rows = 3, columns = -5, status;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_equal) {
  matrix_t A, B;
  int rows = 3, columns = 5, status;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_equal_double) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  B.matrix[1][3] = 3.141592653;
  A.matrix[1][3] = 3.141592653;
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_equal_double_8digit) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  B.matrix[1][2] = 3.141592601;
  A.matrix[1][2] = 3.141592699;
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_not_equal_row) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns, &B);
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_not_equal_column) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns + 1, &A);
  s21_create_matrix(rows, columns, &B);
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_not_equal_elem) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[2][4] = 5;
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_not_equal_double_6digit) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  B.matrix[2][3] = 3.1415921;
  A.matrix[2][3] = 3.1415911;
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_ne_double_longlong_limit) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[2][3] = 3.141592653589692e+15;
  B.matrix[2][3] = 3.141592653589693e+15;
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_ne_double_superbig) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[2][3] = 3.141592653589692e+300;
  B.matrix[2][3] = 3.141592653589693e+300;
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_ne_double_sign) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[2][3] = -3.141592653589692e+30;
  B.matrix[2][3] = 3.141592653589693e+30;
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(is_ne_double_exp) {
  matrix_t A, B;
  int rows = 3, columns = 5, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[2][3] = 3.141592653589692e+300;
  B.matrix[2][3] = 3.141592653589693e+299;
  status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_suite() {
  Suite *s_eq;
  TCase *tc_compare;

  s_eq = suite_create("\033[45m-=S21_EQ_MATRIX=-\033[0m");

  tc_compare = tcase_create("eq_suite");
  tcase_add_test(tc_compare, neg_rows);
  tcase_add_test(tc_compare, neg_cols);
  tcase_add_test(tc_compare, is_equal);
  tcase_add_test(tc_compare, is_equal_double);
  tcase_add_test(tc_compare, is_equal_double_8digit);
  tcase_add_test(tc_compare, is_not_equal_row);
  tcase_add_test(tc_compare, is_not_equal_column);
  tcase_add_test(tc_compare, is_not_equal_elem);
  tcase_add_test(tc_compare, is_not_equal_double_6digit);
  tcase_add_test(tc_compare, is_ne_double_longlong_limit);
  tcase_add_test(tc_compare, is_ne_double_superbig);
  tcase_add_test(tc_compare, is_ne_double_sign);
  tcase_add_test(tc_compare, is_ne_double_exp);
  suite_add_tcase(s_eq, tc_compare);

  return s_eq;
}
