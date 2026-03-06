/**
 * @file test_math.c
 * @author Andrea Drahovská (xdrahoa00@stud.fit.vutbr.cz)
 * @brief Testy pro knihovnu mathlib
 * @date 2026-03-05
 */

#include "mathlib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_addition) {
  ck_assert_int_eq(addition(1, 2), 3);
  ck_assert_int_eq(addition(-1, 1), 0);
  ck_assert_int_eq(addition(-100, 1), -99);
  ck_assert_int_eq(addition(12, 15), 27);
}
END_TEST

START_TEST(test_subtraction) {
  ck_assert_int_eq(subtraction(10, 4), 6);
  ck_assert_int_eq(subtraction(0, 5), -5);
  ck_assert_int_eq(subtraction(50, 75), -25);
  ck_assert_int_eq(subtraction(500, 500), 0);
  ck_assert_int_eq(subtraction(0, 5), -5);
}
END_TEST

// sada testu
Suite *math_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MathLib_Tests");
  tc_core = tcase_create("Core_Operations");

  tcase_add_test(tc_core, test_addition);
  tcase_add_test(tc_core, test_subtraction);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}