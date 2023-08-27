#ifndef SRC_TESTS_S21_TESTS_H_
#define SRC_TESTS_S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *s21_create_suite();
// Suite *s21_common_suite();
Suite *s21_transpose_suite();
Suite *s21_calc_complements_suite();
Suite *s21_determinant_suite();
Suite *s21_eq_suite();
Suite *s21_inverse_suite();
Suite *s21_mult_matrix_suite();
Suite *s21_mult_number_suite();
Suite *s21_remove_suite();
Suite *s21_sub_suite();
Suite *s21_sum_suite();
// Suite *s21_another_suite();

#endif  // SRC_TESTS_S21_TESTS_H_
