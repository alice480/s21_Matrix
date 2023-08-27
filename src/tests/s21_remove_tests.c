#include "s21_tests.h"

START_TEST(remove_matrix_legal) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_double_eq(A.rows, 0);
  ck_assert_double_eq(A.columns, 0);
}
END_TEST

START_TEST(remove_uncorrect_matrix) {
  matrix_t A;
  s21_create_matrix(-1, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_double_eq(A.rows, 0);
  ck_assert_double_eq(A.columns, 0);
}
END_TEST

Suite *s21_remove_suite() {
  Suite *s_remove;
  TCase *tc_legal;

  s_remove = suite_create("\033[45m-=S21_REMOVE_MATRIX=-\033[0m");

  tc_legal = tcase_create("remove_suite");
  tcase_add_test(tc_legal, remove_matrix_legal);
  tcase_add_test(tc_legal, remove_uncorrect_matrix);
  suite_add_tcase(s_remove, tc_legal);

  return s_remove;
}
