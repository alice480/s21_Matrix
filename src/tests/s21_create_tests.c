#include "s21_tests.h"

START_TEST(correct_matrix) {
  matrix_t A;
  int status = s21_create_matrix(3, 4, &A);
  ck_assert_double_eq(A.rows, 3);
  ck_assert_double_eq(A.columns, 4);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(uncorrect_matrix_zero) {
  matrix_t B;
  ck_assert_int_eq(s21_create_matrix(0, 1, &B), UNCORRECT_MATRIX);
}
END_TEST

START_TEST(uncorrect_matrix_negative) {
  matrix_t C;
  ck_assert_int_eq(s21_create_matrix(3, -4, &C), UNCORRECT_MATRIX);
}
END_TEST

Suite *s21_create_suite(void) {
  Suite *s = suite_create("\033[45m-=S21_CREATE=-\033[0m");
  TCase *tc = tcase_create("create_tc");

  tcase_add_test(tc, correct_matrix);
  tcase_add_test(tc, uncorrect_matrix_zero);
  tcase_add_test(tc, uncorrect_matrix_negative);

  suite_add_tcase(s, tc);
  return s;
}