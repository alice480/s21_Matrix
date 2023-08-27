#include "s21_tests.h"

int main(void) {
  int failed = 0;

  Suite *s21_matrix_test[] = {s21_create_suite(),
                              s21_remove_suite(),
                              s21_eq_suite(),
                              s21_sum_suite(),
                              s21_sub_suite(),
                              s21_mult_number_suite(),
                              s21_mult_matrix_suite(),
                              s21_transpose_suite(),
                              s21_calc_complements_suite(),
                              s21_determinant_suite(),
                              s21_inverse_suite(),
                              NULL};

  for (int i = 0; s21_matrix_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *runner = srunner_create(s21_matrix_test[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);

    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n");
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
