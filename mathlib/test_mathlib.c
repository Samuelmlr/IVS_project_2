/**
 * @file test_math.c
 * @author Andrea Drahovská (xdrahoa00@stud.fit.vutbr.cz)
 * @brief Testy pro knihovnu mathlib
 * @date 2026-03-05
 */

#include "mathlib.h"
#include <check.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Testuje funkci addition pro sčítání reálných čísel.
 * * Test zahrnuje:
 * - sčítání celých čísel předaných jako double
 * - sčítání kladných desetinných čísel
 * - sčítání záporných desetinných čísel
 * - sčítání velmi malých hodnot (ověření přesnosti)
 */
START_TEST(test_addition) {
  // Celá čísla jako double
  ck_assert_double_eq_tol(addition(1.0, 2.0), 3.0, 0.001);
  ck_assert_double_eq_tol(addition(-100.0, 1.0), -99.0, 0.001);

  // Desetinná čísla
  ck_assert_double_eq_tol(addition(1.5, 0.2), 1.7, 0.001);
  ck_assert_double_eq_tol(addition(100.1, 9.9), 110.0, 0.001);

  // Záporná desetinná čísla
  ck_assert_double_eq_tol(addition(-1.5, -2.5), -4.0, 0.001);
  ck_assert_double_eq_tol(addition(-10.5, 5.2), -5.3, 0.001);

  // Velmi malá čísla
  ck_assert_double_eq_tol(addition(0.0001, 0.0002), 0.0003, 0.00001);
}
END_TEST

/**
 * @brief Testuje funkci subtraction pro odčítání reálných čísel.
 * * Test zahrnuje:
 * - základní rozdíly celých čísel
 * - odečítání desetinných čísel
 * - odečítání záporných čísel (ověření znaménkových pravidel)
 */
START_TEST(test_subtraction) {
  // Základní
  ck_assert_double_eq_tol(subtraction(10.0, 4.0), 6.0, 0.001);
  ck_assert_double_eq_tol(subtraction(0.0, 5.0), -5.0, 0.001);

  // Desetinná
  ck_assert_double_eq_tol(subtraction(5.5, 2.1), 3.4, 0.001);
  ck_assert_double_eq_tol(subtraction(1.1, 1.1), 0.0, 0.001);

  // Odčítání záporného čísla
  ck_assert_double_eq_tol(subtraction(5.0, -2.5), 7.5, 0.001);
  ck_assert_double_eq_tol(subtraction(-10.2, -1.2), -9.0, 0.001);
}
END_TEST

/**
 * @brief Testuje násobení reálných čísel.
 */
START_TEST(test_multiplication) {
  ck_assert_double_eq_tol(multiplication(1.0, 2.0), 2.0, 0.001);
  ck_assert_double_eq_tol(multiplication(-2.0, 5.0), -10.0, 0.001);
  ck_assert_double_eq_tol(multiplication(1.5, 2.0), 3.0, 0.001);
  ck_assert_double_eq_tol(multiplication(0.0, 50.5), 0.0, 0.001);
  ck_assert_double_eq_tol(multiplication(0.2, 0.2), 0.04, 0.001);
}
END_TEST

/**
 * @brief Testuje dělení reálných čísel včetně dělení nulou.
 */
START_TEST(test_division) {
  ck_assert_double_eq_tol(division(10.0, 2.0), 5.0, 0.001);
  ck_assert_double_eq_tol(division(5.0, 4.0), 1.25, 0.001);
  ck_assert_double_eq_tol(division(-10.0, 4.0), -2.5, 0.001);

  // Test dělení nulou - očekáváme not a number
  double result = division(5.0, 0.0);
  ck_assert_msg(isnan(result), "Dělení nulou musí vrátit NAN");
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
  tcase_add_test(tc_core, test_multiplication);
  tcase_add_test(tc_core, test_division);

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